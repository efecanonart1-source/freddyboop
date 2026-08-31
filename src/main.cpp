#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class FreddyLayer : public CCLayer {
protected:
    bool init() {
        if (!CCLayer::init())
            return false;

        auto size = CCDirector::sharedDirector()->getWinSize();

        // Freddy görseli
        auto freddy = CCSprite::create("freddy.png");
        if (!freddy)
            return true;

        freddy->setPosition(size / 2);

        float scaleX = size.width / freddy->getContentSize().width;
        float scaleY = size.height / freddy->getContentSize().height;
        freddy->setScale(std::min(scaleX, scaleY) * 0.8f);

        this->addChild(freddy);

        // Burna tıklanabilir alan
        auto nose = CCMenuItemSpriteExtra::create(
            CCLayerColor::create({255, 255, 255, 1}),
            this,
            menu_selector(FreddyLayer::onNose)
        );

        nose->setContentSize({100.f, 80.f});
        nose->setOpacity(0);

        // Freddy'nin yaklaşık merkezine koyuyoruz.
        nose->setPosition(size / 2 + CCPoint{0.f, -20.f});

        auto menu = CCMenu::create();
        menu->setPosition(0, 0);
        menu->addChild(nose);

        this->addChild(menu, 10);

        return true;
    }

    void onNose(CCObject*) {
        log::info("Freddy nose clicked!");
    }

public:
    static FreddyLayer* create() {
        auto ret = new FreddyLayer();

        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }

        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

class $modify(FreddyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto size = CCDirector::sharedDirector()->getWinSize();

        // Ana menüdeki Freddy butonu
        auto sprite = CCSprite::create("freddy.png");

        if (!sprite)
            return true;

        sprite->setScale(0.12f);

        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(FreddyMenuLayer::onFreddy)
        );

        auto menu = CCMenu::create();
        menu->setPosition(0, 0);
        menu->addChild(button);

        // SOL ÜST
        button->setPosition({55.f, size.height - 55.f});

        this->addChild(menu, 100);

        return true;
    }

    void onFreddy(CCObject*) {
        auto layer = FreddyLayer::create();

        if (layer)
            this->addChild(layer, 1000);
    }
};
