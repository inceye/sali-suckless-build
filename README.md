A build of various [suckless](https://suckless.org) tools, as well as a script to install and configure them all
===

To easily install this build of suckless tools, simply, as non-root user and non-root user only, go into the git's root directory and run

``` 
./deploy 
```
---

This is [OUR](https://en.wikipedia.org/wiki/Soviet_Union) build of the following suckless tools:

* Browser [Surf](surf)

    A restyled fork of [original Surf browser](https://surf.suckless.org/) with several
    patches:

    * [Bookmarks](https://surf.suckless.org/patches/bookmarking/)
    * [Argument for cache directory](https://surf.suckless.org/patches/cachedir/)
    * [GTK clipboard instead of primary](https://surf.suckless.org/patches/clipboard-instead-of-primary/)
    * [Download console](https://surf.suckless.org/patches/dlconsole/)
    * [History file and navigation](https://surf.suckless.org/patches/history/)
    * [Homepage](https://surf.suckless.org/patches/homepage/)
    * [External video player pipe](https://surf.suckless.org/patches/playexternal/)
    * [Multiple search engines](https://surf.suckless.org/patches/searchengines/)
    * [Space search - search by typing a space before url](https://surf.suckless.org/patches/spacesearch/)

* Screen locker utility [Slock](slock)

    A restyled fork of [the original Slock screen locker](https://tools.suckless.org/slock/)
    by suckless with several patches:

    * [Blurred screen as background](https://tools.suckless.org/slock/patches/blur-pixelated-screen/)
    * [Display power manager](https://tools.suckless.org/slock/patches/dpms/)
    * [Message display](https://tools.suckless.org/slock/patches/message/)
    * [Quick cancel by moving mouse immediately after lock](https://tools.suckless.org/slock/patches/quickcancel/)
    * [Terminal keybinds support](https://tools.suckless.org/slock/patches/quickcancel/)

    as well as my own patch, that adds stars as you type in the password and 
    some fixes of patch conflicts.

* Tab utility to add tabs to any program you want [Tabbed](tabbed)

    A restyled fork of [the original tabbed utility](https://tools.suckless.org/tabbed/) 
    by suckless with several patches:

    * [Addition of client number to the tab](https://tools.suckless.org/tabbed/patches/clientnumber/)
    * [Automatic tab hiding when not pressing the keybinds](https://tools.suckless.org/tabbed/patches/hidetabs/)
    * [Keyrelease patch required by hidetabs](https://tools.suckless.org/tabbed/patches/keyrelease/)
 
* Window manager [DWM](dwm)

    A decimated fork of [LukeSmithXYZ's build of DWM](https://github.com/LukeSmithxyz/dwm) 
    with so many patches that it is not even obvious LukeSmith created the 
    initial version of this :

    * [Unique settings for different tags](https://dwm.suckless.org/patches/pertag/)
        with my own addition of different settings for any combination of
        tags as well. Also I added gaps to the list of things that are
        unique for each tag.
    * [Display status on all connected monitors](https://dwm.suckless.org/patches/statusallmons/)
    * [Gapless grid]() but with gaps
    * [Winview]()
    * [Bar height]()
    * [Bar padding]()
    * [Bar alpha]()
    * [Layout menu]()
    * [Warp]() but with more customizability to prevent cursor warping when
        it is not something you want.
    * [Status button]()
    * [Resize corners]()

* Status for it [DWMBlocks](dwmblocks)
    A restyled fork of [LukesmithXYZ's build of DWMblocks](https://github.com/lukesmithxyz/dwmblocks), with a couple of my own scripts

* Terminal emulator [ST](st)
    A restyled fork of [LukesmithXYZ's build of ST](https://github.com/LukeSmithxyz/st)

* Simple menu [dmenu](dmenu)
    A restyled fork of [LukesmithXYZ's build of dmenu](https://github.com/LukeSmithxyz/dmenu)

This build also has a couple of scripts needed for dwmblock to work correctly.
