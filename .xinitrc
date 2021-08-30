feh --bg-fill wallpaper.jpg &
picom --corner-radius=15 --round-borders 1 &
dunst &
dwmblocks_unkill &
/etc/status/handlers/PowerHandler &
xrandr --output DP1 --right-of HDMI2 &
xautolock -time 60 -locker slock &
remaps &
exec dwm
