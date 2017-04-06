#pragma once

#include <string>

using namespace std;

static wstring sCoordinates = L"Координаты";
static wstring sHP = L"Здоровье  ";
static wstring sXP = L"Опыт      ";
static wstring sStrength = L"Сила     ";
static wstring sDexterity = L"Ловкость ";
static wstring sIntelligence = L"Интеллект";
static wstring sLevel = L"Уровень   ";
static wstring sMonsters[2] = { L"Летучий мыш", L"Гоблин" };
static wstring sCWeapon = L"Оружие : ";
static wstring sCArmor = L"Броня  : ";
static wstring sIncExp1 = L"Получено ";
static wstring sIncExp2 = L" опыта";
static wstring sNewLevel = L"Новый уровень!";
static wstring sDamageToEnemy = L"Нанесен урон ";
static wstring sDamageToHero1 = L" нанес ";
static wstring sDamageToHero2 = L" урона";
static wstring sKilling = L" убит!";
static wstring sDodged = L" увернулся!";
static wstring sHeroDodged = L"Вы увернулись от ";
static wstring sNoDamage = L" не пробил защиту";
static wstring sReceived = L"Получено ";
static wstring sItems[6] = { L"Железный меч", L"Копье", L"Стальной меч", L"Кожанная броня", L"Кольчуга", L"Латные доспехи" };
static wstring sMotion = L"Движение";
static wstring sAttack = L"Атака";
static wstring sInventory = L"Инвентарь";
static wstring sCharacteristics = L"Характеристики";
static wstring sDodgeСhance = L"Шанс увернуться";
static wstring sMenu = L"Меню";
static wstring sInfo = L"Информация";
static wstring sHints = L"Управление";
static wstring sSelect = L"Выбор";
static wstring sUse = L"Использовать";
static wstring sDelete = L"Выкинуть";
static wstring sBack = L"Назад";
static wstring sDamage = L"Урон  ";
static wstring sDefense = L"Защита";
static wstring sMaxHP = L"Максимальное здоровье";
static wstring sPoints = L"Очки";
static wstring sAccept = L"Принять";
static wstring sClear = L"Очистить";
static wstring sIncrease = L"Увеличить";
static wstring sDecrease = L"Уменьшить";
static wstring sMulExp = L"Множитель опыта";
static wstring sVisDistance = L"Дальность обзора";
static wstring sSkip = L"Пропуск хода";
static wstring sDeath = L"Вы убиты!";
static wstring sContinue = L"Продолжить";
static wstring sSave = L"Сохранить";
static wstring sLoad = L"Загрузить";
static wstring sNewGame = L"Новая игра";
static wstring sNewMap = L"Новая карта";
static wstring sSettings = L"Настройки";
static wstring sExit = L"Выход";
static wstring sTileSize = L"Размер тайла";
static wstring sTileNum = L"Количество тайлов";
static wstring sResolution = L"Разрешение (примерно)";
static wstring sSelectRace = L"Выберите расу";
static wstring sRaceHuman = L"Человек (+ к ловкости и интеллекту)";
static wstring sRaceDwarf = L"Дварф (+ к силе и интеллекту)";
static wstring sRaceElf = L"Эльф (+ к силе и ловкости)";
static wstring sRace = L"Раса";
static wstring sRaces[3] = { L"Человек", L"Дварф", L"Эльф" };

static wstring sDelimeter = L": ";
static wstring sSlash = L" / ";
static wstring sComma = L", ";
static wstring sSpace = L" ";
static wstring sAsterisk = L"*";
static wstring sPercent = L"%";
static wstring sRadio = L"( ) ";
static wstring sLack = L"---";
static wstring sWindowName = L"Valden";
static wstring skArrows = L"arrows";
static wstring skWASD = L"wasd";
static wstring skI = L"i";
static wstring skC = L"c";
static wstring skEsc = L"Esc";
static wstring skPlus = L"+";
static wstring skMinus = L"-";
static wstring skEnter = L"Enter";
static wstring skSpace = L"Space";
static wstring skTab = L"Tab";
static wstring sX = L"x";
static wstring sLoading = L"Загрузка...";
static wstring sMapSave = L"Map.sv";
static wstring sHeroSave = L"Hero.sv";
static wstring sNPCSave = L"NPC.sv";
static wstring sSettingsSave = L"settings.sv";
static wstring sSavePath = L"save/";
static wstring sSaveDin = L"din.";
static wstring sVersion[2] = { L"Страница проекта",  L"Вышла новая версия " };
static wstring sCopyright[2] = { L"https://github.com/evost/Valden-builds",  L"(c) github.com/evost" };
static wstring sVersionURL = L"https://raw.githubusercontent.com/evost/Valden-builds/master/version.md";
static wstring sLogo[5] = {
	L" _    __        __     __           ",
	L"| |  / /____ _ / /____/ /___   ____ ",
	L"| | / // __ `// // __  // _ \\ / __ \\",
	L"| |/ // /_/ // // /_/ //  __// / / /",
	L"|___/ \\__,_//_/ \\__,_/ \\___//_/ /_/ "
};
static wstring sHistory[24] = {
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
