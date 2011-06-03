#include "Functions.h"

AMX_NATIVE_INFO Functions::vaultmp_functions[] = {

    {"GetPlayerName", Functions::vaultmp_GetPlayerName},
    {"GetPlayerPos", Functions::vaultmp_GetPlayerPos},
    {"GetPlayerZAngle", Functions::vaultmp_GetPlayerZAngle},
    {0, 0}

};

int Functions::RegisterVaultmpFunctions(AMX* amx)
{
    return Script::Register(amx, Functions::vaultmp_functions, -1);
}

cell Functions::vaultmp_GetPlayerName(AMX* amx, const cell* params)
{
    int i = 1, len, id;
    cell* dest;

    id = (int) params[1];
    amx_GetAddr(amx, params[2], &dest);

    RakNetGUID guid = Client::GetGUIDFromID(id);
    Player* player = Player::GetPlayerFromGUID(guid);

    if (player != NULL)
    {
        string pname = player->GetPlayerName();
        char name[pname.length()];
        strcpy(name, pname.c_str());

        amx_SetString(dest, name, 0, 0, strlen(name) + 1);
    }
    else
        i = 0;

    return i;
}

cell Functions::vaultmp_GetPlayerPos(AMX* amx, const cell* params)
{
    int i = 1, id;

    id = (int) params[1];

    RakNetGUID guid = Client::GetGUIDFromID(id);
    Player* player = Player::GetPlayerFromGUID(guid);

    if (player != NULL)
    {
        float pos = player->GetPlayerPos((int) params[2]);
        return amx_ftoc(pos);
    }
    else
        i = 0;

    return i;
}

cell Functions::vaultmp_GetPlayerZAngle(AMX* amx, const cell* params)
{
    int i = 1, id;

    id = (int) params[1];

    RakNetGUID guid = Client::GetGUIDFromID(id);
    Player* player = Player::GetPlayerFromGUID(guid);

    if (player != NULL)
    {
        float angle = player->GetPlayerAngle();
        return amx_ftoc(angle);
    }
    else
        i = 0;

    return i;
}