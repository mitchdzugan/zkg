{
  description = "(x11/wayland roots) keyboard grabber and key press reporter";
  inputs.nixpkgs.url = "nixpkgs/nixos-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";
  inputs.zn-nix.url = "github:mitchdzugan/zn.nix";
  inputs.zn-nix.inputs.nixpkgs.follows = "nixpkgs";
  inputs.zkg-wlr-f.url = "github:mitchdzugan/zkg-wlr";
  inputs.zkg-x11-f.url = "github:mitchdzugan/zkg-x11";
  outputs = { self, nixpkgs, zn-nix, flake-utils, zkg-wlr-f, zkg-x11-f, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        zn = zn-nix.mk-zn system;
        zkg-x11 = zkg-x11-f.packages.${system}.default;
        zkg-wlr = zkg-wlr-f.packages.${system}.default;
      in rec {
        packages.default = packages.zkg;
        packages.zkg = zn.writeBbScriptBin' "zkg" [zkg-x11 zkg-wlr] ''
          (require '[babashka.process :refer [shell]])
          (def bin (if (= (System/getenv "XDG_SESSION_TYPE") "wayland")
                     "${zkg-wlr}/bin/zkg-wlr"
                     "${zkg-x11}/bin/zkg-x11"))
          (apply shell bin *command-line-args*)
        '';
    });
}
