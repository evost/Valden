#pragma once

#include "strings.h"

wstring sCoordinates = L"����������";
wstring sHP = L"��������";
wstring sXP = L"����";
wstring sStrength = L"����";
wstring sDexterity = L"��������";
wstring sIntelligence = L"���������";
wstring sLevel = L"�������";
wstring sMonsters[NPCTypesNum] = {
	L"����",
	L"�����",
	L"����",
	L"������",
	L"�����",
	L"�������",
	L"���",
	L"������",
	L"��������",
	L"���"
};
wstring sCWeapon = L"������ : ";
wstring sCArmor = L"�����  : ";
wstring sIncExp = L" �����";
wstring sNewLevel = L"����� �������!";
wstring sDamageToEnemy = L"������� ���� ";
wstring sDamageToHero1 = L" ����� ";
wstring sDamageToHero2 = L" �����";
wstring sKilling = L" ����!";
wstring sDodged = L" ���������!";
wstring sHeroDodged = L"�� ���������� �� ";
wstring sNoDamage = L" �� ������ ������";
wstring sReceived = L"�������� ";
wstring sSeeTrap = L"�� ���������� �������";
wstring sDisarmTrap = L"�� ����������� �������";
wstring sFallTrap = L"�� ������ � �������";
wstring sItems[itemsNum + poulticeNum] = {
	L"������",
	L"������������ ������",
	L"������",
	L"������� ����",
	L"�����",
	L"��������",
	L"������",
	L"�������� �����",
	L"�����",
	L"�������� �����",
	L"������",
	L"��������",
	L"������ �����",
	L"�������� ������",
	L"�������� ���",
	L"������������ ������",
	L"������ �����",
	L"�������� ������",
	L"�������� ���",
	L"������ ������",
	L"������",
	L"�����",
	L"��������"
};
wstring sMotion = L"��������";
wstring sAttack = L"�����";
wstring sInventory = L"���������";
wstring sCharacteristics = L"��������������";
wstring sDodge�hance = L"���� ����������";
wstring sSeeTrapChance = L"���� �������� �������";
wstring sDisarmTrapChance = L"���� ����������� �������";
wstring sMenu = L"����";
wstring sInfo = L"����������";
wstring sHints = L"����������";
wstring sSelect = L"�����";
wstring sUse = L"������������";
wstring sDelete = L"��������";
wstring sBack = L"�����";
wstring sDamage = L"����";
wstring sDefense = L"������";
wstring sMaxHP = L"������������ ��������";
wstring sPoints = L"����";
wstring sKilled = L"�����";
wstring sAccept = L"�������";
wstring sClear = L"��������";
wstring sIncrease = L"���������";
wstring sDecrease = L"���������";
wstring sMulExp = L"��������� �����";
wstring sVisDistance = L"��������� ������";
wstring sSkip = L"������� ����";
wstring sDeath = L"����� �����!";
wstring sContinue = L"����������";
wstring sSave = L"���������";
wstring sLoad = L"���������";
wstring sNewGame = L"����� ����";
wstring sNewMap = L"����� �����";
wstring sSettings = L"���������";
wstring sExit = L"�����";
wstring sTileSize = L"������ �����";
wstring sTileNum = L"���������� ������";
wstring sResolution = L"���������� (��������)";
wstring sSelectRace = L"�������� ����";
wstring sRaceHuman = L"������� (+ � �������� � ����������)";
wstring sRaceDwarf = L"����� (+ � ���� � ����������)";
wstring sRaceElf = L"���� (+ � ���� � ��������)";
wstring sRace = L"����";
wstring sRaces[3] = { L"�������", L"�����", L"����" };
wstring sDelimeter = L": ";
wstring sSlash = L" / ";
wstring sComma = L", ";
wstring sSpace = L" ";
wstring sAsterisk = L"*";
wstring sPercent = L"%";
wstring sRadio = L"( ) ";
wstring sLack = L"---";
wstring sWindowName = L"Valden";
wstring skArrows = L"arrows";
wstring skWASD = L"wasd";
wstring skI = L"i";
wstring skC = L"c";
wstring skEsc = L"Esc";
wstring skPlus = L"+";
wstring skMinus = L"-";
wstring skEnter = L"Enter";
wstring skSpace = L"Space";
wstring skTab = L"Tab";
wstring skBckspc = L"Bckspc";
wstring sX = L"x";
wstring sPlus = L" +";
wstring sLoading = L"��������...";
wstring sMapSave = L"Map.sv";
wstring sHeroSave = L"Hero.sv";
wstring sNPCSave = L"NPC.sv";
wstring sSettingsSave = L"settings.sv";
wstring sSavePath = L"save/";
wstring sSaveDin = L"din.";
wstring sVersion[2] = { L"�������� �������",  L"����� ����� ������ " };
wstring sCopyright[2] = { L"https://github.com/evost/Valden-builds",  L"(c) github.com/evost" };
wstring sVersionURL = L"https://raw.githubusercontent.com/evost/Valden-builds/master/version.md";
wstring sLogo[logoSize] = {
	L" _    __        __     __           ",
	L"| |  / /____ _ / /____/ /___   ____ ",
	L"| | / // __ `// // __  // _ \\ / __ \\",
	L"| |/ // /_/ // // /_/ //  __// / / /",
	L"|___/ \\__,_//_/ \\__,_/ \\___//_/ /_/ "
};
wstring sHistory[historySize] = {
	L"��� ����� ��� ���� ��� ������ ������ ���� ������������.",
	L"��� ����� ������ ���� ����� �������� � ���������� ����",
	L"������ �� ������������ ������� ���������� �������.",
	L"������, ���������� ������ �������,",
	L"����� � ������ ��������� �������.",
	L"�������, �� �������� �� ���� ����� - ������ ����� �����",
	L"��������� � ������������� ������.������ � ���� ���� �� ����",
	L"�������� ������, �, ������ ��������� ���� � �����, ��",
	L"��������� ����� ���� �� ���� - ��, ��� ������� � �����.",
	L"������.����, ������ - ���, ��� ���������� ����������� �����",
	L"������.�������� ������ ��������� ������ � ���������",
	L"������ - � ������ �������.",
	L"���, ��� �������� � �����, ������� �� �������� � ��������,",
	L"��� ������ �� ��������� �� ������ � �������� �� ������� �",
	L"������� ����� � �����.",
	L"������ ������, ������, �� �������� ������, ����� ���,",
	L"��� ���� �� ������� ����� ������ � �������� ������",
	L"��� ����� ������������.",
	L"� ������� �� �������� ������ ����� ��������, ��� �� ����� -",
	L"������� ���� ��������� ����� ��� ��������� ���� �������",
	L"����� �� ������.",
	L"�� ��� ��� ����� ����� ��� �������� �����.",
	L" ",
	L"������� ����� ������� ��� �����������."
};
