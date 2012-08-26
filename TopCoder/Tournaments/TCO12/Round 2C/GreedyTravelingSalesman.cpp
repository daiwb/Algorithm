// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

// BEGIN CUT HERE
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}
// END CUT HERE

// BEGIN CUT HERE
int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}
// END CUT HERE

int len[35][35];
int fl[35];
int ff[10005];

class GreedyTravelingSalesman {
public:
    int worstDistance(vector <string> thousands, vector <string> hundreds, vector <string> tens, vector <string> ones) {
        int n = thousands.size();
        REP(i,n) {
            REP(j,n) {
                len[i][j] = (thousands[i][j] - '0') * 1000 + (hundreds[i][j] - '0') * 100 + (tens[i][j] - '0') * 10 + ones[i][j] - '0';
            }
        }
        int res = 0;
        REP(x,n) {
            REP(y,n) {
                if (x == y) continue;
                memset(ff, 0, sizeof(ff));
                REP(q,n) {
                    if (q == x) continue;
                    int l = len[x][q];
                    ff[l] = 1;
                    if (l > 1) ff[l - 1] = 1;
                }
                ff[1] = ff[9999] = 1;
                vector<int> dd;
                FOR(i,1,9999) {
                    if (ff[i] == 1) dd.push_back(i);
                }
                REP(k,dd.size()) {
                    int bak = len[x][y];
                    len[x][y] = dd[k];
                    int tot = 0;
                    memset(fl, 0, sizeof(fl));
                    fl[0] = 1;
                    int cnt = 1, cur = 0;
                    while (true) {
                        int p = -1, idx = -1;
                        REP(i,n) {
                            if (fl[i] == 1) continue;
                            if (p == -1 || len[cur][i] < p) {
                                p = len[cur][i];
                                idx = i;
                            }
                        }
                        cur = idx;
                        fl[idx] = 1;
                        tot += p;
                        ++cnt;
                        if (cnt == n) break;
                    }
                    len[x][y] = bak;
                    res = max(res, tot);
                }
            }
        }
        return res;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string thousandsARRAY[] = {"055", "505", "550"};
        vector <string> thousands( thousandsARRAY, thousandsARRAY+ARRSIZE(thousandsARRAY) );
        string hundredsARRAY[] = {"000", "000", "000"};
        vector <string> hundreds( hundredsARRAY, hundredsARRAY+ARRSIZE(hundredsARRAY) );
        string tensARRAY[] = {"000", "000", "000"};
        vector <string> tens( tensARRAY, tensARRAY+ARRSIZE(tensARRAY) );
        string onesARRAY[] = {"000", "000", "000"};
        vector <string> ones( onesARRAY, onesARRAY+ARRSIZE(onesARRAY) );
        GreedyTravelingSalesman theObject;
        eq(0, theObject.worstDistance(thousands, hundreds, tens, ones),14999);
    }
    {
        string thousandsARRAY[] = {"018", "101", "990"};
        vector <string> thousands( thousandsARRAY, thousandsARRAY+ARRSIZE(thousandsARRAY) );
        string hundredsARRAY[] = {"000", "000", "990"};
        vector <string> hundreds( hundredsARRAY, hundredsARRAY+ARRSIZE(hundredsARRAY) );
        string tensARRAY[] = {"000", "000", "990"};
        vector <string> tens( tensARRAY, tensARRAY+ARRSIZE(tensARRAY) );
        string onesARRAY[] = {"000", "000", "990"};
        vector <string> ones( onesARRAY, onesARRAY+ARRSIZE(onesARRAY) );
        GreedyTravelingSalesman theObject;
        eq(1, theObject.worstDistance(thousands, hundreds, tens, ones),17999);
    }
    {
        string thousandsARRAY[] = {"00888", "00999", "00099", "00009", "00000"}
           ;
        vector <string> thousands( thousandsARRAY, thousandsARRAY+ARRSIZE(thousandsARRAY) );
        string hundredsARRAY[] = {"00000", "00999", "00099", "00009", "00000"}
           ;
        vector <string> hundreds( hundredsARRAY, hundredsARRAY+ARRSIZE(hundredsARRAY) );
        string tensARRAY[] = {"00000", "10999", "11099", "11109", "11110"}
           ;
        vector <string> tens( tensARRAY, tensARRAY+ARRSIZE(tensARRAY) );
        string onesARRAY[] = {"01000", "00999", "00099", "00009", "00000"}
           ;
        vector <string> ones( onesARRAY, onesARRAY+ARRSIZE(onesARRAY) );
        GreedyTravelingSalesman theObject;
        eq(2, theObject.worstDistance(thousands, hundreds, tens, ones),37997);
    }
    {
        string thousandsARRAY[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
        vector <string> thousands( thousandsARRAY, thousandsARRAY+ARRSIZE(thousandsARRAY) );
        string hundredsARRAY[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
        vector <string> hundreds( hundredsARRAY, hundredsARRAY+ARRSIZE(hundredsARRAY) );
        string tensARRAY[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
        vector <string> tens( tensARRAY, tensARRAY+ARRSIZE(tensARRAY) );
        string onesARRAY[] = {"011111", "101111", "990998", "999099", "999809", "999980"};
        vector <string> ones( onesARRAY, onesARRAY+ARRSIZE(onesARRAY) );
        GreedyTravelingSalesman theObject;
        eq(3, theObject.worstDistance(thousands, hundreds, tens, ones),39994);
    }
    {
        string thousandsARRAY[] = {"00", "00"};
        vector <string> thousands( thousandsARRAY, thousandsARRAY+ARRSIZE(thousandsARRAY) );
        string hundredsARRAY[] = {"00", "00"};
        vector <string> hundreds( hundredsARRAY, hundredsARRAY+ARRSIZE(hundredsARRAY) );
        string tensARRAY[] = {"00", "00"};
        vector <string> tens( tensARRAY, tensARRAY+ARRSIZE(tensARRAY) );
        string onesARRAY[] = {"01", "10"};
        vector <string> ones( onesARRAY, onesARRAY+ARRSIZE(onesARRAY) );
        GreedyTravelingSalesman theObject;
        eq(4, theObject.worstDistance(thousands, hundreds, tens, ones),9999);
    }
    {
        string thousandsARRAY[] = {"0930", "1064", "0104", "1070"};
        vector <string> thousands( thousandsARRAY, thousandsARRAY+ARRSIZE(thousandsARRAY) );
        string hundredsARRAY[] = {"0523", "1062", "6305", "0810"};
        vector <string> hundreds( hundredsARRAY, hundredsARRAY+ARRSIZE(hundredsARRAY) );
        string tensARRAY[] = {"0913", "0087", "3109", "1500"};
        vector <string> tens( tensARRAY, tensARRAY+ARRSIZE(tensARRAY) );
        string onesARRAY[] = {"0988", "2030", "6103", "5530"};
        vector <string> ones( onesARRAY, onesARRAY+ARRSIZE(onesARRAY) );
        GreedyTravelingSalesman theObject;
        eq(5, theObject.worstDistance(thousands, hundreds, tens, ones),14124);
    }
    {
        string thousandsARRAY[] = {"0329", "2036", "2502", "8970"};
        vector <string> thousands( thousandsARRAY, thousandsARRAY+ARRSIZE(thousandsARRAY) );
        string hundredsARRAY[] = {"0860", "5007", "0404", "2770"};
        vector <string> hundreds( hundredsARRAY, hundredsARRAY+ARRSIZE(hundredsARRAY) );
        string tensARRAY[] = {"0111", "2087", "2009", "2670"};
        vector <string> tens( tensARRAY, tensARRAY+ARRSIZE(tensARRAY) );
        string onesARRAY[] = {"0644", "1094", "7703", "7550"};
        vector <string> ones( onesARRAY, onesARRAY+ARRSIZE(onesARRAY) );
        GreedyTravelingSalesman theObject;
        eq(6, theObject.worstDistance(thousands, hundreds, tens, ones),17785);
    }
    {
        string thousandsARRAY[] = {"098444156277392825243100607342", "200097656837707947798866622385",
           "290231695687128834848596019656", "407026565077650435591867333275",
           "843401002617957470339040852874", "349970591997218853400632158696",
           "419933000593511123878416328483", "696294503254214847884399055978",
           "641473980706392541888675375279", "936720077098054565078142449625",
           "203476089500970673371115103717", "511071853860312304204656816567",
           "347105714685052402147763392257", "125122220860203856679947732062",
           "121462979669220132944063071653", "928254504048223043681383050365",
           "502607124708785202536036594373", "793596587517012870906900400361",
           "712360060935346182084840996318", "761671392040312345002273366240",
           "812935320276738878200716148806", "228506917464479046839069740872",
           "755395721473881083093906155745", "192597782177910118061710039501",
           "721382839206745793530453013267", "076061794267810491768114700256",
           "857528357758085424372388710251", "173322450800442594145600093043",
           "761667192345925280210514410800", "521229810525064090301842864060"};
        vector <string> thousands( thousandsARRAY, thousandsARRAY+ARRSIZE(thousandsARRAY) );
        string hundredsARRAY[] = {"098270581534726237580246464451", "108829763716747148395013332067",
           "830061279541380758964430491222", "431005058477371114834129826284",
           "601807314489142917339949914290", "330640126699733151822328009407",
           "851821069798846354566780680271", "648888407535627630663351884365",
           "051398660825518466890170447894", "631934884097214069747147155777",
           "768071219404930950472885304916", "924954163330715847561718395488",
           "189910033179029204426829479070", "960645776060701332402794474433",
           "244875842263950931884758650019", "528470075229660077692189442311",
           "752198673046476808978058423064", "899325998610605600525587569431",
           "965750123741820904031880230236", "121658852172052167706008445728",
           "556199378085507717770434101126", "864838242791403197110088834005",
           "593435343245223500439707230479", "622529771475840345624500421425",
           "503486612623475041392122088159", "518334626169655694269507400008",
           "967091631529233593414345370288", "300474162107271438029222620086",
           "010527691044447729596127150108", "742822904991333205419603623270"};
        vector <string> hundreds( hundredsARRAY, hundredsARRAY+ARRSIZE(hundredsARRAY) );
        string tensARRAY[] = {"029421809872798033258029765788", "705135039569772524273274786652",
           "170567418260893393020344098265", "401043354947659563658581268242",
           "746709065616595245635350557925", "739570024549618413776557843034",
           "184597012262496958610853505745", "689811400727818703807051112784", 
           "894453010121164288965541305235", "323145029073008946088869964941", 
           "834269564400729646453274750586", "538976762970745472202055589093", 
           "765511399939087047106252621388", "906733295711605356366138410423", 
           "107653940551700559321642810836", "428402693021051075533830345295", 
           "386782660475155103347385287948", "936626025836194580089064628716", 
           "718522629491464055045890912121", "370656945845300237607868352243", 
           "951908186614186444840337711498", "535178875249889835014025850038", 
           "505970047705717604298603983975", "484398304612602344941130624527", 
           "048342694079170795987835013947", "860331019262176299872846206272", 
           "549663926438975145562538360932", "329735455392841851511474791078", 
           "711755200061373546828858448100", "778808866574640894148527759780"};
        vector <string> tens( tensARRAY, tensARRAY+ARRSIZE(tensARRAY) );
        string onesARRAY[] = {"050738147930236727719964251439", "804492562859282318664226330103", 
           "610197568193830684654773608216", "279000416545607314567843085541", 
           "782201171759873927350740022455", "043370803444176631019883186675", 
           "566092086050401228622782761449", "469598907881602996036692882305", 
           "116923500417992303845370254124", "796876115092839169954790509461", 
           "783836410405270687557924090071", "095144151150833738671751747749", 
           "354474585664039135189964700948", "328968176148004939648962631420", 
           "829651915384290848347221555092", "170980383407813034573738951375", 
           "728655435703349509419725538350", "121896684176286430427852435647", 
           "315710894574884960021671476788", "592177839598531202003634382961", 
           "876587919610157913350259498196", "505517243779897451333006271744", 
           "618607877753891664471800511372", "826358757330233811836040764274", 
           "206641252044293046424432092833", "704519364781672964993499009545", 
           "624793571592392775564426440338", "571938479010503551295729304078", 
           "077967252884369103891335711508", "870185204806328841827105139840"};
        vector <string> ones( onesARRAY, onesARRAY+ARRSIZE(onesARRAY) );
        GreedyTravelingSalesman theObject;
        eq(7, theObject.worstDistance(thousands, hundreds, tens, ones),39896);
    }
    return 0;
}
// END CUT HERE
