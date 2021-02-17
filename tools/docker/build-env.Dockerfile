FROM spack/ubuntu-bionic:latest

WORKDIR /sources

# Mount the current sources into the build container
# and build the default environment
RUN --mount=type=bind,source=.,target=/sources \
    spack env create --without-view ci /sources/tools/environments/ci/spack.yaml && \
    spack -e ci repo add /sources/tools/spack && \
    spack -e ci install --fail-fast --only=dependencies -v && \
    spack env rm -y ci && \
    spack clean -a