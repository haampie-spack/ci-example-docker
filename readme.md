[![CI](https://github.com/haampie-spack/ci-example/actions/workflows/ci.yaml/badge.svg)](https://github.com/haampie-spack/ci-example/actions/workflows/ci.yaml) [![Update build environment](https://github.com/haampie-spack/ci-example/actions/workflows/build-env.yaml/badge.svg)](https://github.com/haampie-spack/ci-example/actions/workflows/build-env.yaml)
# Build and run locally:

```sh
$ git clone https://github.com/haampie-spack/ci-example.git
$ docker run -h build-env -v ci-example:/sources -it stabbles/pkg-example
root@build-env:/sources# apt-get update -qq && apt-get install -qq --no-install-recommends ssh # todo: figure out how to get rid of this, openmpi wants it apparently
root@build-env:/sources# spack repo add tools/spack
root@build-env:/sources# spack -e tools/environments/ci install --test=root --verbose mypkg@main
```

# Build the build environment locally:

```sh
$ cd ci-example
$ DOCKER_BUILDKIT=1 docker build . -f tools/docker/build-env.Dockerfile -t stabbles/pkg-example
```

# Running with GPU in the container
If you want to enable gpu support, you might need to pass `--gpus ...` to docker:

```sh
$ docker run --gpus 'all,"capabilities=compute,utility"' -h build-env -v ci-example:/sources -it stabbles/pkg-example
```