FROM spack/ubuntu-bionic:latest

WORKDIR /sources

# Mount the current sources into the build container
# and build the default environment
RUN --mount=type=bind,source=.,target=/sources \
    spack --color=always env create --without-view ci /sources/tools/environments/ci/spack.yaml && \
    spack --color=always -e ci repo add /sources/tools/spack && \
    spack --color=always -e ci install --fail-fast --only=dependencies && \
    spack --color=always env rm -y ci && \
    spack --color=always clean -a
