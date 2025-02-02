#pragma once

#include "InventoryHandler.h"
#include "ItemModificationHandler.h"
#include "ItemRemovalHandler.h"
#include "RequestTypes.h"
#include "StorageUnitHandler.h"
#include <InventoryChanger/Backend/Item.h>
#include <InventoryChanger/Backend/Response/Response.h>
#include <InventoryChanger/Backend/Response/ResponseAccumulator.h>
#include <InventoryChanger/Backend/Response/ResponseQueue.h>
#include <InventoryChanger/GameItems/CrateLootLookup.h>
#include <InventoryChanger/GameItems/Lookup.h>

namespace inventory_changer::backend
{

class ItemIDMap;
class Loadout;
class PickEm;
class StorageUnitManager;
class XRayScanner;

struct RequestHandler {
    RequestHandler(ItemModificationHandler<ResponseAccumulator> itemModificationHandler, ItemRemovalHandler<ResponseAccumulator> itemRemovalHandler, InventoryHandler<ResponseAccumulator> inventoryHandler, StorageUnitHandler<ResponseAccumulator> storageUnitHandler, XRayScanner& xRayScanner, ResponseAccumulator responseAccumulator, ItemList& inventory, Loadout& loadout, const game_items::Lookup& gameItemLookup, const game_items::CrateLootLookup& crateLootLookup, ItemConstRemover constRemover)
        : itemModificationHandler{ itemModificationHandler }, itemRemovalHandler{ itemRemovalHandler }, inventoryHandler{ inventoryHandler }, storageUnitHandler{ storageUnitHandler }, xRayScanner{ xRayScanner }, responseAccumulator{ responseAccumulator }, inventory{ inventory }, loadout{ loadout }, gameItemLookup{ gameItemLookup }, crateLootLookup{ crateLootLookup }, constRemover{ constRemover } {}

    void operator()(const request::ApplySticker& request) const;
    void operator()(const request::WearSticker& request) const;
    void operator()(const request::SwapStatTrak& request) const;
    void operator()(const request::ApplyPatch& request) const;
    void operator()(const request::RemovePatch& request) const;
    void operator()(const request::AddNameTag& request) const;
    void operator()(const request::RemoveNameTag& request) const;
    void operator()(const request::ActivateSouvenirToken& request) const;
    void operator()(const request::UnsealGraffiti& request) const;

private:
    ItemModificationHandler<ResponseAccumulator> itemModificationHandler;
    ItemRemovalHandler<ResponseAccumulator> itemRemovalHandler;
    InventoryHandler<ResponseAccumulator> inventoryHandler;
    StorageUnitHandler<ResponseAccumulator> storageUnitHandler;
    XRayScanner& xRayScanner;
    ResponseAccumulator responseAccumulator;
    ItemList& inventory;
    Loadout& loadout;
    const game_items::Lookup& gameItemLookup;
    const game_items::CrateLootLookup& crateLootLookup;
    ItemConstRemover constRemover;
};

}
