{
  description = "A collection of point, size and rect classes for C++";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-22.05";
    flake-utils.url = "github:numtide/flake-utils";

    tinycmmc.url = "github:grumbel/tinycmmc";
    tinycmmc.inputs.nixpkgs.follows = "nixpkgs";
    tinycmmc.inputs.flake-utils.follows = "flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, tinycmmc }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in {
        packages = flake-utils.lib.flattenTree rec {
          geomcpp = pkgs.stdenv.mkDerivation {
            pname = "geomcpp";
            version = tinycmmc.lib.versionFromFile self;
            src = nixpkgs.lib.cleanSource ./.;
            postPatch = ''
              echo "v${tinycmmc.lib.versionFromFile self}" > VERSION
            '';
            doCheck = true;
            cmakeFlags = [
              "-DWARNINGS=ON"
              "-DWERROR=ON"
              "-DBUILD_TESTS=ON"
            ];
            nativeBuildInputs = with pkgs; [
              cmake
            ];
            buildInputs = with pkgs; [
              gtest
            ] ++ [
              tinycmmc.packages.${system}.default
            ];
            propagatedBuildInputs = with pkgs; [
              glm
            ];
           };
          default = geomcpp;
        };
      }
    );
}
