# Godot XR Reference plugin

![GitHub forks](https://img.shields.io/github/forks/godotvr/godot_xr_reference?style=plastic)
![GitHub Repo stars](https://img.shields.io/github/stars/godotvr/godot_xr_reference?style=plastic)
![GitHub contributors](https://img.shields.io/github/contributors/godotvr/godot_xr_reference?style=plastic)
![GitHub](https://img.shields.io/github/license/godotvr/godot_xr_reference?style=plastic)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/godotvr/godot_xr_reference?style=plastic)

This is a reference plugin to use as a base to implement XR plugins for Godot 4 and later.

This example XR interface implements simple side by side output with lens distortion and reacts to WASD and mouse input to move the player around. Click on the screen to capture input, press escape to release input.
![screenshot](screenshot.png)

## Building this plugin
Make sure that when you clone this repository you initialise the submodules recursively.

Simply compile the plugin with:
```
scons target=template_debug
```

> It is important to build debug builds as the editor requires debug builds to run. You can build a release build to distribute alongside your game with `target=template_release`.

# VSCode
For convencience I've added my `tasks.json` build configuration for `vscode` into this repository. This included the above mentioned build instructions.

# Demo

The demo folder contains an example project that implement this interface and is used as the build destination when compiling the plugin.

# Initialising the interface

To use the interface it has to be initialised. This code is similar to that of other XR interfaces in Godot:

```
var xr_interface: XRInterfaceReference

func start_xr():
	var xr_interface = XRServer.find_interface("XR Reference");
	if xr_interface:
		print("Capabilities " + str(xr_interface.get_capabilities()))
		print("Target size " + str(xr_interface.get_render_target_size()))

		if xr_interface.initialize():
			get_viewport().use_xr = true

			print("Initialised")
		else:
			print("Failed to initialise")
	else:
		print("Interface was not instantiated")
```

# About the author

This repository is maintained by Bastiaan "Mux212" Olij
Further information to follow.
