{
  description = "A collection of point, size and rect classes for C++";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs?ref=nixos-25.05";

    tinycmmc.url = "github:grumbel/tinycmmc";
    tinycmmc.inputs.nixpkgs.follows = "nixpkgs";
  };

  outputs = { self, nixpkgs, tinycmmc }:
    tinycmmc.lib.eachSystemWithPkgs (pkgs:
      {
        packages = rec {
          default = geomcpp;

          geomcpp = pkgs.callPackage ./geomcpp.nix {
            inherit self;
            tinycmmc_lib = tinycmmc.lib;
            tinycmmc = tinycmmc.packages.${pkgs.system}.default;

            # Allow the glm package on systems other than Unix
            glm = pkgs.glm.overrideAttrs (oldAttrs: { meta = {}; });
          };
        };
      }
    );
}
