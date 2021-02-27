# Copyright 2013-2021 Lawrence Livermore National Security, LLC and other
# Spack Project Developers. See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (Apache-2.0 OR MIT)

# ----------------------------------------------------------------------------
# If you submit this package back to Spack as a pull request,
# please first remove this boilerplate and all FIXME comments.
#
# This is a template package file for Spack.  We've put "FIXME"
# next to all the things you'll want to change. Once you've handled
# them, you can save this file and test your package like this:
#
#     spack install mypackage
#
# You can edit this file again by typing:
#
#     spack edit mypackage
#
# See the Spack documentation for more information on packaging.
# ----------------------------------------------------------------------------

from spack import *


class Mypkg(CMakePackage):
    """Example package"""

    homepage = "https://github.com/haampie-spack/ci-example"
    git      = "https://github.com/haampie-spack/ci-example.git"

    maintainers = ['haampie']

    version('main', branch='main')

    variant('cuda', default=False, description="Enable CUDA support")
    variant('mpi', default=False, description="Enable MPI support")
    variant('shared', default=True, description="Build shared libraries")

    depends_on('cuda', when="+cuda")
    depends_on('mpi', when="+mpi")

    def cmake_args(self):
        args = [
            self.define_from_variant('MYPKG_USE_CUDA', 'cuda'),
            self.define_from_variant('MYPKG_USE_MPI', 'mpi'),
            self.define_from_variant('MYPKG_BUILD_SHARED', 'shared'),
            self.define('MYPKG_BUILD_TESTS', 'ON' if self.run_tests else 'OFF')
        ]

        return args