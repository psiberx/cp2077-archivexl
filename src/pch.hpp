#pragma once

#include <algorithm>
#include <concepts>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <future>
#include <map>
#include <memory>
#include <ranges>
#include <source_location>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

#include <RED4ext/RED4ext.hpp>

#include <RED4ext/JobQueue.hpp>
#include <RED4ext/ResourceDepot.hpp>
#include <RED4ext/ResourceLoader.hpp>
#include <RED4ext/Scripting/Natives/ScriptGameInstance.hpp>
#include "RED4ext/Scripting/Natives/Generated/game/Puppet.hpp"
#include "RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationInfo.hpp"
#include "RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationInfoResource.hpp"
#include "RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationOption.hpp"
#include "RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationState.hpp"
#include "RED4ext/Scripting/Natives/Generated/game/ui/ICharacterCustomizationSystem.hpp"
#include "RED4ext/Scripting/Natives/Generated/game/ui/MorphInfo.hpp"
#include "RED4ext/Scripting/Natives/Generated/game/ui/OptionsGroup.hpp"
#include <RED4ext/Scripting/Natives/Generated/CMesh.hpp>
#include <RED4ext/Scripting/Natives/Generated/JsonResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/MorphTargetMesh.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/LipsyncMapping.hpp>
#include <RED4ext/Scripting/Natives/Generated/appearance/AppearanceDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/appearance/AppearancePartOverrides.hpp>
#include <RED4ext/Scripting/Natives/Generated/appearance/AppearanceResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/AnimatedComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ComponentsStorage.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/Entity.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/EntityID.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/EntityTemplate.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/MeshComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/MorphTargetSkinnedMeshComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/SkinnedClothComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/SkinnedMeshComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/TemplateAppearance.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/VisualTagsSchema.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/AppearanceNameVisualTagsPreset.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/AttachmentSlots.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IGameSystem.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ITransactionSystem.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/JournalManager.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/JournalQuestMapPin.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/JournalResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/JournalRootFolderEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/JournalTree.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/MappinResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ScriptableSystem.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/TPPRepresentationComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/ItemsFactoryAppearanceSuffixBase_Record.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/mappins/IMappinVolume.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/AppearanceInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationFeetController.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/SwitcherInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/IWidgetController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Widget.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetLibraryItemInstance.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetLibraryResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetLogicController.hpp>
#include <RED4ext/Scripting/Natives/Generated/loc/VoLanguageDataMap.hpp>
#include <RED4ext/Scripting/Natives/Generated/localization/PersistenceOnScreenEntries.hpp>
#include <RED4ext/Scripting/Natives/Generated/localization/PersistenceSubtitleMap.hpp>
#include <RED4ext/Scripting/Natives/Generated/mesh/MeshAppearance.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/GlobalNodeID.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/GlobalNodeRef.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/RuntimeSystemEntityAppearanceChanger.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/StreamingBlock.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/StreamingWorld.hpp>

#include <nameof.hpp>
#include <semver.hpp>

#include <yaml-cpp/yaml.h>

#include "Core/Raw.hpp"
#include "Core/Stl.hpp"

#include "Red/Alias.hpp"
#include "Red/Framework.hpp"
#include "Red/LogChannel.hpp"
#include "Red/TypeInfo.hpp"
#include "Red/Specializations.hpp"
#include "Red/Utils.hpp"
