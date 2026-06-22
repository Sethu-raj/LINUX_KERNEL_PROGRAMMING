savedcmd_/home/sethuraj/LINUX_KERNEL/init/init.mod := printf '%s\n'   init.o | awk '!x[$$0]++ { print("/home/sethuraj/LINUX_KERNEL/init/"$$0) }' > /home/sethuraj/LINUX_KERNEL/init/init.mod
