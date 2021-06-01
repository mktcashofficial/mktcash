
Debian
====================
This directory contains files used to package mktcashd/mktcash-qt
for Debian-based Linux systems. If you compile mktcashd/mktcash-qt yourself, there are some useful files here.

## mktcash: URI support ##


mktcash-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install mktcash-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your mktcashqt binary to `/usr/bin`
and the `../../share/pixmaps/mktcash128.png` to `/usr/share/pixmaps`

mktcash-qt.protocol (KDE)

