savedcmd_/home/sethuraj/LINUX_KERNEL/debug/debug.mod := printf '%s\n'   debug.o | awk '!x[$$0]++ { print("/home/sethuraj/LINUX_KERNEL/debug/"$$0) }' > /home/sethuraj/LINUX_KERNEL/debug/debug.mod
