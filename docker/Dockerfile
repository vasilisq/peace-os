FROM alpine:latest

RUN apk update
RUN apk add gcc make
RUN apk add grub
RUN apk add xorriso grub-bios mtools dosfstools apk-tools squashfs-tools

WORKDIR src

CMD ["make"]