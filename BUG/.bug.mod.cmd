savedcmd_/home/vboxuser/LINUXKERNEL/BUG/bug.mod := printf '%s\n'   bug.o | awk '!x[$$0]++ { print("/home/vboxuser/LINUXKERNEL/BUG/"$$0) }' > /home/vboxuser/LINUXKERNEL/BUG/bug.mod
