#include <iostream>
#include <vector>
using namespace std;

#include "..\..\source\player\Classes\CSoul.h"

int main()
{

std::vector<CSoul> SoulFactory;

// Name      HP Agi Dex Str Ldr Wis Mrk Mec Exp Med Lvl Daily$ Skill #1 Skill #2
CSoul Barry;//     82  72  87  80  29  91  70  44  92  20   2    700 Electr.  Lockpick
SoulFactory.push_back(CSoul("Barry"));
CSoul Blood;//     84  94  87  82   6  75  78  23  31  51   3    850 Throwing M. Arts
SoulFactory.push_back(CSoul("Blood"));
CSoul Bull;//      96  59  44  98  23  64  72  25  17  10   2    400 H2H      (Expert)
SoulFactory.push_back(CSoul(""));
CSoul Buns;//      79  78  87  59  24  93  86   8   4  48   2    725 Teaching (Expert)
SoulFactory.push_back(CSoul(""));
CSoul Buzz;//      71  84  47  68  13  90  96   5  19   0   4   2200 HeavyWpn AutoWpns
SoulFactory.push_back(CSoul(""));
CSoul Cliff;//     82  60  53  64  33  87  84   4  31  84   4   1600 -------- --------
SoulFactory.push_back(CSoul(""));
CSoul Danny;//     99  99  79  73  10  91  61  12   0  88   3   1300 Ambidext --------
SoulFactory.push_back(CSoul(""));
CSoul DrQ;//     88  92  81  73  26  91  60  19  20  87   3   1500 M. Arts  NightOps
SoulFactory.push_back(CSoul(""));
CSoul Fidel;//     88  83  64  83   1  71  85   6  97   3   3   2000 H2H      --------
SoulFactory.push_back(CSoul(""));
CSoul Fox;//       77  85 100  55  21  76  69  15   8  70   2    625 Teaching Ambidext
SoulFactory.push_back(CSoul(""));
CSoul Grizzly;//   94  69  50  95  16  72  79  24  37   8   2    525 H2H      HeavyWpn
SoulFactory.push_back(CSoul(""));
CSoul Grunty;//    82  79  76  71  21  72  78  44  28  22   3    550 NightOps HeavyWpn
SoulFactory.push_back(CSoul(""));
CSoul Gus;//       75  65  84  82  83  94  97  80  76  68   8   6000 HeavyWpn (Expert)
SoulFactory.push_back(CSoul(""));
CSoul Hitman;//    75  77  40  69  52  74  88  11  39   3   4   1000 Throwing Teaching
SoulFactory.push_back(CSoul(""));
CSoul Ice;//       90  88  87  84  23  78  86  42   3   7   3   1500 Teaching AutoWpns
SoulFactory.push_back(CSoul(""));
CSoul Igor;//      91  89  75  82   4  84  77  36  19  17   2    500 Stealth  --------
SoulFactory.push_back(CSoul(""));
CSoul Ivan;//      94  90  95  87  35  83  92  14  55  15   4   2950 AutoWpns HeavyWpn
SoulFactory.push_back(CSoul(""));
CSoul Len;//       89  80  88  77  61  83  83  54  47  35   7   2400 AutoWpns Teaching
SoulFactory.push_back(CSoul(""));
CSoul Lynx;//      81  79  86  77  39  71  99  29  50  34   4   2850 Electr.  NightOps
SoulFactory.push_back(CSoul(""));
CSoul Magic;//     95  99  98  92  16  80  94  91  27  24   5   5500 Lockpick Stealth
SoulFactory.push_back(CSoul(""));
CSoul Malice;//    83  81  97  89  13  55  83  14  16  12   3   1200 Knifing  H2H
SoulFactory.push_back(CSoul(""));
CSoul MD;//        72  62  78  76   4  94  66   7   0  80   1    500 Knifing  Teaching
SoulFactory.push_back(CSoul(""));
CSoul Meltdown;//  78  74  84  76  24  82  83  22  40   3   3    800 HeavyWpn Ambidext
SoulFactory.push_back(CSoul(""));
CSoul Nails;//     72  60  88  90  24  79  84  63  78  11   4   1800 Lockpick --------
SoulFactory.push_back(CSoul(""));
CSoul Raider;//    80  71  78  80  87  76  88  12  20  11   4   2000 Teaching (Expert)
SoulFactory.push_back(CSoul(""));
CSoul Raven;//     85  76  92  68  19  77  94   5   5  17   2   1800 NightOps AutoWpns
SoulFactory.push_back(CSoul(""));
CSoul Reaper;//    81  92  92  79  37  81  97  37  47   2   6   4000 Stealth  On-roof
SoulFactory.push_back(CSoul(""));
CSoul Red;//       68  66  81  69  21  79  78  33  99   5   4    900 Teaching Electr.
SoulFactory.push_back(CSoul(""));
CSoul Scope;//     87  89  76  64  39  81  99   4  21  17   5   2900 NightOps Teaching
SoulFactory.push_back(CSoul(""));
CSoul Scully;//    90  90  96  85  70  93  92  61  66  36   5   4800 Knifing  (Expert)
SoulFactory.push_back(CSoul(""));
CSoul Shadow;//    95  96  83  88  35  77  92  12  22  30   5   3100 Stealth  Camo
SoulFactory.push_back(CSoul(""));
CSoul Sidney;//    80  70  91  76  27  78  92   2  15  44   5   2000 Throwing (Expert)
SoulFactory.push_back(CSoul(""));
CSoul Spider;//    81  56  76  68  16  90  70   0   0  94   1    800 NightOps Stealth
SoulFactory.push_back(CSoul(""));
CSoul Static;//    79  66  95  59  15  60  86  99  28  17   4   2500 Electr.  NightOps
SoulFactory.push_back(CSoul(""));
CSoul Stephen;//   97  71  78  80  59  94  82  15  66  15   5   1500 NightOps Teaching
SoulFactory.push_back(CSoul(""));
CSoul Steroid;//   99  56  48  97   9  62  89  76  13  22   1    950 Electr.  Lockpick
SoulFactory.push_back(CSoul(""));
CSoul Thor;//      96  83  84  89  61  97  74  35  11  70   3   1750 H2H      Stealth
SoulFactory.push_back(CSoul(""));
CSoul Trevor;//    95  77  98  79  27  97  81  99  88   7   2   2800 Electr.  Lockpick
SoulFactory.push_back(CSoul(""));
CSoul Vicki;//     79  85  72  72  33  85  85  94  28  18   4   2200 Ambidext Throwing
SoulFactory.push_back(CSoul(""));
CSoul Wolf;//      90  83  86  85  22  76  79  65  40  48   3   1400 Teaching NightOps
SoulFactory.push_back(CSoul(""));
//M.E.R.C.

//Name      HP Agi Dex Str Ldr Wis Mrk Mec Exp Med Lvl Daily$ Skill #1 Skill #2
CSoul Biff;//      73  74  71  41  14  58  57   0   4  24   2    200 Teaching --------
SoulFactory.push_back(CSoul("Biff"));
CSoul Bubba;//     86  54  68  98   5  29  77  59  61   0   4    600 H2H      --------
SoulFactory.push_back(CSoul("Bubba"));
CSoul Cougar;//    88  83  79  87  31  75  93  58  45  33   5   2000 AutoWpns Stealth
SoulFactory.push_back(CSoul("Cougar"));
CSoul Flo;//       58  37  64  45   1  82  38   7   2  19   1    100 Teaching --------
SoulFactory.push_back(CSoul("Flo"));
CSoul Gasket;//    72  61  89  68   3  49  44  82   8   0   1    200 Lockpick --------
SoulFactory.push_back(CSoul("Gasket"));
CSoul Gaston;// *  88  82  96  84  28  80  94  22  21  23   6  11500 NightOps On-roof
SoulFactory.push_back(CSoul("Gaston"));
CSoul Gumpy;//     67  45  67  70  11  94  44   0  56   9   1    150 Electr.  --------
SoulFactory.push_back(CSoul("Gumpy"));
CSoul Haywire;//   65  59  76  71   1  58  48   8  31   2   1    150 AutoWpns Knifing
SoulFactory.push_back(CSoul("Haywire"));
CSoul Larry;//     69  87  79  67  18  70  70  14  92  70   3    700 Stealth  Lockpick
SoulFactory.push_back(CSoul("Larry"));
// CSoul Larry;// X   69  72  54  35   4  58  50   7  82  49   1    700 -------- --------
CSoul Numb;//      84  72  61  78  10  70  88  11  13  30   3    900 NightOps M. Arts
SoulFactory.push_back(CSoul("Numb"));
CSoul Razor;//     73  88  91  86   4  53  50   8  11  12   2    150 Knifing  (Expert)
SoulFactory.push_back(CSoul("Razor"));
CSoul Stogie;// *  98  78  84  96  33  77  89  74  43  11   7  14000 HeavyWpn (Expert)
SoulFactory.push_back(CSoul("Stogie"));
//Recruitable NPCs

//Name      HP Agi Dex Str Ldr Wis Mrk Mec Exp Med Lvl Daily$ Skill #1 Skill #2
CSoul Biggins;// * 78  61  68  55  64  81  79  71  92  17   7   3500 NightOps Electr.
SoulFactory.push_back(CSoul("Biggins"));
CSoul Carlos;//    79  91  61  68  38  71  67  34  20  11   4      0 Throwing Stealth
SoulFactory.push_back(CSoul("Carlos"));
CSoul Conrad;//    76  69  84  81  51  88  95  22  68  49   5   5500 Teaching AutoWpns
SoulFactory.push_back(CSoul("Conrad"));
CSoul Devin;//     73  61  88  71  11  72  67  34  96   2   3    800 Electr.  Knifing
SoulFactory.push_back(CSoul("Devin"));
CSoul Dimitri;//   75  73  51  71  21  56  77  71  12  17   1      0 Throwing (Expert)
SoulFactory.push_back(CSoul("Dimtri"));
CSoul Dynamo;//    76  57  67  55   8  78  68  67   9  21   1     50 Lockpick (Expert)
SoulFactory.push_back(CSoul("Dynamo"));
CSoul Hamous;//    68  68  66  69   5  35  78  19   0   0   2    250 Stealth  --------
SoulFactory.push_back(CSoul("Hamous"));
CSoul Iggy;//      88  81  79  85  15  71  87  42  21  33   5   1950 HeavyWpn (Expert)
SoulFactory.push_back(CSoul("Iggy"));
CSoul Ira;//       76  72  91  55  14  83  55   8   2  40   2      0 Teaching (Expert)
SoulFactory.push_back(CSoul("Ira"));
CSoul John;// *    67  51  60  66   8  65  95  88   2   8   3      0 AutoWpns (Expert)
SoulFactory.push_back(CSoul("John"));
CSoul Maddog;//    91  91  92  78   8  56  66  68  18   7   1      0 Lockpick (Expert)
SoulFactory.push_back(CSoul("Maddog"));
CSoul Manuel;// *  76  72  91  76  45  83  78   8  22  40   4      0 Stealth  (Expert)
SoulFactory.push_back(CSoul("Manuel"));
CSoul Miguel;//    88  73  76  83  98  80  85  22  31  13   6      0 NightOps Knifing
SoulFactory.push_back(CSoul("Miguel"));
CSoul Shank;//     73  36  43  31   7  80  45  11   9  17   1     20 Throwing (Expert)
SoulFactory.push_back(CSoul("Shank"));
CSoul Terry;//     80  76  78  77  16  59  93  44  34  10   4      0 On-roof  AutoWpns
SoulFactory.push_back(CSoul("Terry"));
CSoul Tex;// *     81  77  74  70   3  52  88  44   2   4   4      0 Ambidext Camo
SoulFactory.push_back(CSoul("Tex"));
CSoul Vince;//     94  49  92  69  33  94  35  13   3  94   2    500 Teaching Ambidext
SoulFactory.push_back(CSoul("Vince"));


cin.get();
return 0;

}