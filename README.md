A build of various [suckless](suckless.org) tools, as well as a script to install and configure them all
===

To easily install this build of suckless tools, simply, as non-root user and non-root user only, go into the git's root directory and run

``` 
./deploy 
```
---

This is my build of the following suckless tools:

* Browser [Surf](surf)

    A restiled fork of original [Surf](http://surf.suckless.org/) browser with several
    patches:

    * [Bookmarks](http://surf.suckless.org/patches/bookmarking/)
    * [Argument for cache directory](http://surf.suckless.org/patches/cachedir/)
    * [GTK clipboard instead of primary](http://surf.suckless.org/patches/clipboard-instead-of-primary/)
    * [Download console](http://surf.suckless.org/patches/dlconsole/)
    * [History file and navigation](http://surf.suckless.org/patches/history/)
    * [Homepage](http://surf.suckless.org/patches/homepage/)
    * [External video player pipe](http://surf.suckless.org/patches/playexternal/)
    * [Multiple search engines](http://surf.suckless.org/patches/searchengines/)
    * [Space search - search by typing a space before url](http://surf.suckless.org/patches/spacesearch/)

* Screen locker utility [Slock](slock)

    A restiled fork of original [Slock](http://tools.suckless.org/slock/) screen 
    locker by suckless sith several patches:

    * [Blurred screen as background](http://tools.suckless.org/slock/patches/blur-pixelated-screen/)
    * [Display power manager](http://tools.suckless.org/slock/patches/dpms/)
    * [Message display](http://tools.suckless.org/slock/patches/message/)
    * [Quick cancel by moving mouse immediately after lock](http://tools.suckless.org/slock/patches/quickcancel/)
    * [Terminal keybinds support](http://tools.suckless.org/slock/patches/quickcancel/)

    as well as my own patch, that adds stars as you type in the password and 
    some fixes of patch conflicts.

* Tab utility to add tabs to any program you want [Tabbed](tabbed)

    A restiled fork of original [tabbed](http://tools.suckless.org/tabbed/) tool by suckless with several patches:

    * [Addition of client number to the tab](http://tools.suckless.org/tabbed/patches/clientnumber/)
    * [Automatic tab hiding when not pressing the keybinds](http://tools.suckless.org/tabbed/patches/hidetabs/)
    * [Keyrelease patch required by hidetabs](http://tools.suckless.org/tabbed/patches/keyrelease/)
 
* Window manager [DWM](dwm)

    A restiled fork of [LukeSmithXYZ's build of DWM](https://github.com/LukeSmithxyz/dwm) with two patches:

    * [Unique settings for different tags](http://dwm.suckless.org/patches/pertag/)
    * [Display status on all connected monitors](http://dwm.suckless.org/patches/statusallmons/)

* Status for it [DWMBlocks](dwmblocks)
    A restiled fork of [LukesmithXYZ's build of DWMblocks](https://github.com/lukesmithxyz/dwmblocks), with a couple of my own scripts

* Terminal emulator [ST](st)
    A restiled fork of [LukesmithXYZ's build of ST](https://github.com/LukeSmithxyz/st)

* Simple menu [dmenu](dmenu)
    A restiled fork of [LukesmithXYZ's build of dmenu](https://github.com/LukeSmithxyz/dmenu)
