#include <Geode/Geode.hpp>
#include <#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(XPosBiasLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        auto mod = Mod::get();
        if (mod->getSettingValue<bool>("enable-bias")) {
            double bias = mod->getSettingValue<double>("x-bias");
            if (m_player1) {
                m_player1->setPositionX(m_player1->getPositionX() + static_cast<float>(bias));
            }
            if (m_player2) {
                m_player2->setPositionX(m_player2->getPositionX() + static_cast<float>(bias));
            }
        }
        return true;
    }
};/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Adds a one-time virtual x offset to the player(s) when a level starts.
// The engine's float position math then behaves as if the player had
// already traveled that extra distance, so float-precision issues
// (X pos limit / Scroll Speed Bug) show up earlier than they normally
// would at a given TPS. There is no exact linear "Nx faster" formula,
// because float precision degrades in steps at powers of two rather
// than smoothly -- calibrate x-bias by testing in-game.

class $modify(XPosBiasLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        auto mod = Mod::get();
        if (mod->getSettingValue<bool>("enable-bias")) {
            double bias = mod->getSettingValue<double>("x-bias");
            if (m_player1) {
                m_player1->setPositionX(m_player1->getPositionX() + static_cast<float>(bias));
            }
            if (m_player2) {
                m_player2->setPositionX(m_player2->getPositionX() + static_cast<float>(bias));
            }
        }
        return true;
    }
};
