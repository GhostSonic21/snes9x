desktopdir = $(datarootdir)/applications
desktop_DATA = snes9x.desktop

icon16x16dir = $(datarootdir)/icons/hicolor/16x16/apps
icon16x16_DATA = snes9x_16x16.png

icon24x24dir = $(datarootdir)/icons/hicolor/24x24/apps
icon24x24_DATA = snes9x_24x24.png

icon32x32dir = $(datarootdir)/icons/hicolor/32x32/apps
icon32x32_DATA = snes9x_32x32.png

icon64x64dir = $(datarootdir)/icons/hicolor/64x64/apps
icon64x64_DATA = snes9x_64x64.png

icon128x128dir = $(datarootdir)/icons/hicolor/128x128/apps
icon128x128_DATA = snes9x_128x128.png

icon256x256dir = $(datarootdir)/icons/hicolor/256x256/apps
icon256x256_DATA = snes9x_256x256.png

#iconscalabledir = $(datarootdir)/icons/hicolor/scalable/apps
#iconscalable_DATA = snes9x.svg

cheatsdir = $(datadir)/snes9x
cheats_DATA = ../../data/cheats.bml

install-data-hook:
	mv -f $(DESTDIR)$(datarootdir)/icons/hicolor/16x16/apps/snes9x_16x16.png \
	      $(DESTDIR)$(datarootdir)/icons/hicolor/16x16/apps/snes9x.png
	mv -f $(DESTDIR)$(datarootdir)/icons/hicolor/24x24/apps/snes9x_24x24.png \
	      $(DESTDIR)$(datarootdir)/icons/hicolor/24x24/apps/snes9x.png
	mv -f $(DESTDIR)$(datarootdir)/icons/hicolor/32x32/apps/snes9x_32x32.png \
	      $(DESTDIR)$(datarootdir)/icons/hicolor/32x32/apps/snes9x.png
	mv -f $(DESTDIR)$(datarootdir)/icons/hicolor/64x64/apps/snes9x_64x64.png \
	      $(DESTDIR)$(datarootdir)/icons/hicolor/64x64/apps/snes9x.png
	mv -f $(DESTDIR)$(datarootdir)/icons/hicolor/128x128/apps/snes9x_128x128.png \
	      $(DESTDIR)$(datarootdir)/icons/hicolor/128x128/apps/snes9x.png
	mv -f $(DESTDIR)$(datarootdir)/icons/hicolor/256x256/apps/snes9x_256x256.png \
	      $(DESTDIR)$(datarootdir)/icons/hicolor/256x256/apps/snes9x.png
	touch -c $(DESTDIR)$(datarootdir)/icons/hicolor
