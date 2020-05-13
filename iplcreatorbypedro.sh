#!/bin/bash
echo "Installed packages list creator v0.2"
echo "www.bypedro.eu"
echo "Saving APT list to aptlist.txt"
apt list --installed > ./aptlist.txt
echo "Saving DPKG list to dpkglist.txt"
dpkg --get-selections > ./dpkglist.txt
#dpkg-query -l > dpkg.txt
echo "All done. Have fun!"
