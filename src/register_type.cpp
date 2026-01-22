#include "register_types.h"

#include <godot_cpp/godot.hpp>

#include "xr_interface_reference.h"

using namespace godot;

void initialize_xrreference_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<XRInterfaceReference>();
}

void uninitialize_xrreference_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	// Note: our class will be unregistered automatically
}

static Ref<XRInterfaceReference> xr_interface;

static void xrreference_startup_callback() {
	xr_interface.instantiate();
	XRServer::get_singleton()->add_interface(xr_interface);
}

static void xrreference_shutdown_callback() {
	XRServer::get_singleton()->remove_interface(xr_interface);
}

extern "C" {

// Initialization.

GDExtensionBool GDE_EXPORT xrreference_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_xrreference_module);
	init_obj.register_terminator(uninitialize_xrreference_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SERVERS);

	init_obj.register_startup_callback(xrreference_startup_callback);
	init_obj.register_shutdown_callback(xrreference_shutdown_callback);

	return init_obj.init();
}
}
