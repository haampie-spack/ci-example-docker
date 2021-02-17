Building:

```sh
DOCKER_BUILDKIT=1 docker build . -f tools/docker/build-env.Dockerfile -t my-build-env
```

Running with NVIDIA GPU support:

```sh
$ docker run --gpus 'all,"capabilities=compute,utility"' my-build-env
```