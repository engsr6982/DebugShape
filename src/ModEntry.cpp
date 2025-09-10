#include "ModEntry.h"

#include "ll/api/mod/RegisterHelper.h"

namespace debug_shape {

ModEntry& ModEntry::getInstance() {
    static ModEntry instance;
    return instance;
}

bool ModEntry::load() {
    getSelf().getLogger().debug("Loading...");
    // Code for loading the mod goes here.
    return true;
}

bool ModEntry::enable() {
    getSelf().getLogger().debug("Enabling...");
    // Code for enabling the mod goes here.
    return true;
}

bool ModEntry::disable() {
    getSelf().getLogger().debug("Disabling...");
    // Code for disabling the mod goes here.
    return true;
}

} // namespace debug_shape

LL_REGISTER_MOD(debug_shape::ModEntry, debug_shape::ModEntry::getInstance());
