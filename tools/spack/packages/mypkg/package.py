# Copyright 2013-2021 Lawrence Livermore National Security, LLC and other
# Spack Project Developers. See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (Apache-2.0 OR MIT)

from spack import *


class Mypkg(CMakePackage):
    """Example package"""

    homepage    = "https://github.com/haampie-spack/ci-example"
    git         = "https://github.com/haampie-spack/ci-example.git"
    maintainers = ['haampie']

    version('main', branch='main')

    variant('cuda',   default=False, description="Enable CUDA support")
    variant('mpi',    default=False, description="Enable MPI support")
    variant('shared', default=True,  description="Build shared libraries")
    variant('tests',  default=False, description="Build with tests")

    depends_on('cuda', when="+cuda")
    depends_on('mpi', when="+mpi")

    def cmake_args(self):
        return [
            self.define_from_variant('MYPKG_USE_CUDA', 'cuda'),
            self.define_from_variant('MYPKG_USE_MPI', 'mpi'),
            self.define_from_variant('MYPKG_BUILD_SHARED', 'shared'),
            self.define_from_variant('MYPKG_BUILD_TESTS', 'tests')
        ]

    def check(self):
        with working_dir(self.build_directory):
            ctest('--output-on-failure')