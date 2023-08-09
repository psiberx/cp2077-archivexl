#include "System.hpp"
#include "Module.hpp"
#include "Red/Entity.hpp"

Red::CString App::PuppetStateSystem::GetBodyTypeSuffix(Red::ItemID aItemID,
                                                       const Red::WeakHandle<Red::GameObject>& aOwner,
                                                       const Red::Handle<Red::ItemsFactoryAppearanceSuffixBase_Record>&)
{
    auto entityTags = Raw::Entity::Tags(aOwner.instance);
    auto visualTags = Raw::Entity::VisualTags(aOwner.instance);

    for (const auto& bodyType : PuppetStateModule::GetBodyTypes())
    {
        if (entityTags->Contains(bodyType))
        {
            return bodyType.ToString();
        }

        if (visualTags->Contains(bodyType))
        {
            return bodyType.ToString();
        }
    }

    return "";
}

Red::CString App::PuppetStateSystem::GetLegsStateSuffix(Red::ItemID aItemID,
                                                        const Red::WeakHandle<Red::GameObject>& aOwner,
                                                        const Red::Handle<Red::ItemsFactoryAppearanceSuffixBase_Record>&)
{
    switch (PuppetStateModule::GetFeetState(aOwner))
    {
    case PuppetFeetState::Flat: return "Flat";
    case PuppetFeetState::Lifted: return "Lifted";
    case PuppetFeetState::HighHeels: return "HighHeels";
    case PuppetFeetState::FlatShoes: return "FlatShoes";
    case PuppetFeetState::None:
    default: return "";
    }
}
