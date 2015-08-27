# ft_ls
A copy of fuction ls in MacOSX

# Overview
This school project reproduce some features of ls command based on OSX default behavior.
It was made respecting the school norm. This explains that there was no loop and cutting of certain functions.
Work on linux (take MACOS branch for OSX)

#Installation
Just launch:
```
  git clone https://github.com/avallete/ft_ls.git
  cd ft_ls
  make
```

If you have a compilation issue, you can simply use docker with:
```
	docker build ./ -t ftls
	docker run --rm --net host -ti --privileged -v /dev/bus/usb:/dev/bus/usb -v ~/.gradle:/root/.gradle -v \$PWD:/myApp:rw
```

#Options
On linux you can use: ltarR1AuScg options.
On OSX you can use: ltarR1AuUScg options.
