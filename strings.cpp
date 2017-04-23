#pragma once

#include "strings.h"

wstring sCoordinates = L"Координаты";
wstring sHP = L"Здоровье";
wstring sXP = L"Опыт";
wstring sStrength = L"Сила";
wstring sDexterity = L"Ловкость";
wstring sIntelligence = L"Интеллект";
wstring sLevel = L"Уровень";
wstring sMonsters[NPCTypesNum] = {
	L"Крыс",
	L"Вепрь",
	L"Волк",
	L"Гоблин",
	L"Гнолл",
	L"Медведь",
	L"Орк",
	L"Тролль",
	L"Волколак",
	L"Огр"
};
wstring sCWeapon = L"Оружие : ";
wstring sCArmor = L"Броня  : ";
wstring sIncExp = L" опыта";
wstring sNewLevel = L"Новый уровень!";
wstring sDamageToEnemy = L"Нанесен урон ";
wstring sDamageToHero1 = L" нанес ";
wstring sDamageToHero2 = L" урона";
wstring sKilling = L" убит!";
wstring sDodged = L" увернулся!";
wstring sHeroDodged = L"Вы увернулись от ";
wstring sNoDamage = L" не пробил защиту";
wstring sReceived = L"Получено ";
wstring sSeeTrap = L"Вы обнаружили ловушку";
wstring sDisarmTrap = L"Вы обезвредили ловушку";
wstring sFallTrap = L"Вы попали в ловушку";
wstring sItems[itemsNum + poulticeNum] = {
	L"Дубина",
	L"Крестьянская одежда",
	L"Кинжал",
	L"Меховой плащ",
	L"Топор",
	L"Стеганка",
	L"Палица",
	L"Кожанная броня",
	L"Копье",
	L"Клепаная броня",
	L"Булава",
	L"Кольчуга",
	L"Боевой топор",
	L"Железный доспех",
	L"Железный меч",
	L"Пластинчатый доспех",
	L"Боевой молот",
	L"Стальной доспех",
	L"Стальной меч",
	L"Латный доспех",
	L"Молоко",
	L"Пирог",
	L"Припарка"
};
wstring sMotion = L"Движение";
wstring sAttack = L"Атака";
wstring sInventory = L"Инвентарь";
wstring sCharacteristics = L"Характеристики";
wstring sDodgeСhance = L"Шанс увернуться";
wstring sSeeTrapChance = L"Шанс заметить ловушку";
wstring sDisarmTrapChance = L"Шанс обезвредить ловушку";
wstring sMenu = L"Меню";
wstring sInfo = L"Информация";
wstring sHints = L"Управление";
wstring sSelect = L"Выбор";
wstring sUse = L"Использовать";
wstring sDelete = L"Выкинуть";
wstring sBack = L"Назад";
wstring sDamage = L"Урон";
wstring sDefense = L"Защита";
wstring sMaxHP = L"Максимальное здоровье";
wstring sPoints = L"Очки";
wstring sKilled = L"Убито";
wstring sAccept = L"Принять";
wstring sClear = L"Очистить";
wstring sIncrease = L"Увеличить";
wstring sDecrease = L"Уменьшить";
wstring sMulExp = L"Множитель опыта";
wstring sVisDistance = L"Дальность обзора";
wstring sSkip = L"Пропуск хода";
wstring sDeath = L"Герой мертв!";
wstring sContinue = L"Продолжить";
wstring sSave = L"Сохранить";
wstring sLoad = L"Загрузить";
wstring sNewGame = L"Новая игра";
wstring sNewMap = L"Новая карта";
wstring sSettings = L"Настройки";
wstring sExit = L"Выход";
wstring sTileSize = L"Размер тайла";
wstring sTileNum = L"Количество тайлов";
wstring sResolution = L"Разрешение (примерно)";
wstring sSelectRace = L"Выберите расу";
wstring sRaceHuman = L"Человек (+ к ловкости и интеллекту)";
wstring sRaceDwarf = L"Дварф (+ к силе и интеллекту)";
wstring sRaceElf = L"Эльф (+ к силе и ловкости)";
wstring sRace = L"Раса";
wstring sRaces[3] = { L"Человек", L"Дварф", L"Эльф" };
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
wstring sLoading = L"Загрузка...";
wstring sMapSave = L"Map.sv";
wstring sHeroSave = L"Hero.sv";
wstring sNPCSave = L"NPC.sv";
wstring sSettingsSave = L"settings.sv";
wstring sSavePath = L"save/";
wstring sSaveDin = L"din.";
wstring sVersion[2] = { L"Страница проекта",  L"Вышла новая версия " };
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
	L"Еще вчера Ваш отец вел войско против Орды Оскверненных.",
	L"Эта битва должна была стать решающей и освободить весь",
	L"Валден от нескончаемых набегов ужаснейших существ.",
	L"Однако, объеденное войско дварфов,",
	L"людей и эльфов оказалось разбито.",
	L"Сегодня, вы очнулись на поле брани - вокруг трупы ваших",
	L"товарищей и изуродованных тварей.Миазмы и Ваши раны не дают",
	L"свободно дышать, и, собрав последние силы в кулак, Вы",
	L"пытаетесь найти хотя бы кого - то, кто остался в живых.",
	L"Никого.Отец, братья - все, кто отправился завоевывать славу",
	L"мертвы.Остается только подобрать оружие и двигаться",
	L"вперед - к родной деревне.",
	L"Вас, как младшего в семье, никогда не готовили к престолу,",
	L"всю юность вы потратили на службу и скитания по Валдену в",
	L"поисках денег и славы.",
	L"Однако теперь, похоже, не осталось никого, кроме Вас,",
	L"кто смог бы собрать новое войско и одержать победу",
	L"над Ордой Оскверненных.",
	L"В деревне не осталось никого кроме стариков, жен да детей -",
	L"собрать даже маленький отряд для отражения атак нечисти",
	L"будет не просто.",
	L"Но это все равно лучше чем подыхать здесь.",
	L" ",
	L"Нажмите любую клавишу для продолжения."
};
