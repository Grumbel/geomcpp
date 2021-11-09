{
  description = "A collection of point, size and rect classes for C++";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs";
    nix.inputs.nixpkgs.follows = "nixpkgs";
    flake-utils.url = "github:numtide/flake-utils";

    tinycmmc.url = "gitlab:grumbel/cmake-modules";
    tinycmmc.inputs.nix.follows = "nix";
    tinycmmc.inputs.nixpkgs.follows = "nixpkgs";
    tinycmmc.inputs.flake-utils.follows = "flake-utils";
  };

  outputs = { self, nix, nixpkgs, flake-utils, tinycmmc }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in rec {
        packages = flake-utils.lib.flattenTree {
          geomcpp = pkgs.stdenv.mkDerivation {
            pname = "geomcpp";
            version = "0.0.0";
            src = nixpkgs.lib.cleanSource ./.;
            nativeBuildInputs = [
              pkgs.cmake
              pkgs.ninja
              pkgs.gcc
            ];
            buildInputs = [
              tinycmmc.defaultPackage.${system}
            ];
            propagatedBuildInputs = [
              pkgs.glm
            ];
           };
        };
        defaultPackage = packages.geomcpp;
      });
}
