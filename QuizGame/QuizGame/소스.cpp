#define _CRT_SECURE_NO_WARNINGS
#define randomize() srand((unsigned)time(NULL))         
#define random(n) (rand() % (n))                       
/*******************************************************************************************************/
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
/*******************************************************************************************************/
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
/*******************************************************************************************************/
typedef struct {
	char name[100];
	int s; //점수
}player;
/*******************************************************************************************************/
typedef struct {
	const char* question;
	const char* Case[4];
	int answer;
	BOOL already;
}quiz;
/*******************************************************************************************************/
//시사
quiz quizdata1[] = {
	{"범죄 피의자를 구속하기 전에 묵비권이나 변호인의 도움을 받을 권리 등 피의자의 권리에 대해 알려 주어야 한다는 원칙","미란다원칙","엔트로피 법칙","열역학 제1법칙","열역학 제2법칙",1,FALSE},// 1
	{"사람이 아닌 법에 의한 지배를 추구하는 원리로서 자유민주주의와 밀접한 관계를 가지고 있다.","준법주의","법치주의","헌법주의","형법주의",2,FALSE},// 2
	{"선거로 뽑은 대표자가 임기 만료 전에 사망, 사퇴 등의 사유로 결원이 발생하였을 경우에 실시하는 선거","국회의원선거","대통령선거","보궐선거","비례선거",3,FALSE},// 3
	{"국회의원은 헌행범인인 경우를 제외하고는 회기중 국회의 동의없이 체포 또는 구금되지 아니한다 는 헌법상 국회의원에게 주어진 특권","불체포 특권","민주주의 특권","금지특권","헌법특권",1,FALSE},// 4
	{"각 정당이 획득한 득표수에 따라 의석을 배분하는 제도로 사표(死票)를 줄일 수 있고 국민의 의사 를 정확히 반영할 수 있다는 장점이 있다","비례대표제","정당대표제","득표대표제","사표대표제",1,FALSE},// 5
	{"국가에 대해여 인간다운 생활의 보장을 적극적으로 요구할 수 있는 권리로 자본주의 사회의 모순을 해결하기 위하여 20C 초에 복지국가에서 강조된 권리(=생존권적 기본권). 인간다운 생활을 할 권리, 교육을 받을 권리, 근로의 권리, 노동3권, 환경권, 혼인, 가족, 모성, 보건에 대한 권리","노동권","사회권","교육권","인권",2,FALSE},// 6
	{"사회 문제를 해결하기 위한 비용 (공해 제거를 위한 정화 비용, 교통문제 해결을 위한 지하도 건설 문제, 청소년 문제를 해결하기위한 프로그램 개발 비용)","사회적비용","해결비용","문제비용","시사비용",1,FALSE},// 7
	{"하급 법원의 재판에 불복하여 상급 법원에 재판을 청구하는 제도로 1심 법원의 판결(결정)에 불복하여 2심 법원에 청구소( 재항고) 2심 법원의 판결에 불복하여 대법원에 청구==> 항고(재항고)","하소제도","중소제도","상소제도","법소제도",3,FALSE},// 8
	{"다음 중 국가 권력을 나누는 삼권분립의 예로 알맞지 않은 것은?","입법부","행정부","사법부","죽부",4,FALSE},// 9
	{"동일한 범죄에 대하여 거듭 처벌되지 아니 한다","일사부재리의 원칙","이사부재리의 원칙","삼사부재리의 원칙","사사부재리의 원칙",1,FALSE},// 10
};
/*******************************************************************************************************/
//사회와 경제
quiz quizdata2[] = {
	{"‘내 뒷마당에서는 안된다’는 이기주의적 의미로 통용되는 이용어는?","임피현상","님투현상","님비현상","핌비현상",3,FALSE},// 1
	{"근로기준법에서 여성과 관련된 내용으로 명시되어 있지 않은 것은?","생리휴가","산전,산후 휴가","갱 내 근로금지","야근근무금지",4,FALSE},// 2
	{"소음 측정 단위는 어느것인가?","dB","ppm","BOD","COD",1,FALSE},// 3
	{"18세기 중엽 영국에서 시작된 기술혁신과 이에 수반하여 일어난 사회 · 경제 구조의 변혁을 무엇이라 할까요? ","산업혁명","사회혁명","경제혁명","기술혁명",1,FALSE},// 4
	{"다음중 대한민국의 광역시가 아닌 것은?","대전","대구","부산","천안",4,FALSE},// 5
	{"범죄자에게 단기의 자유형을 선고할 때 그 정상을 참작하여 일정기간 동안 그 형을 유예하는 제도인 이 제도는 무엇일까요?","단기유예제도","집행유예제도","정상유예제도","선거유예제도",2,FALSE},// 6
	{"작은 변화가 폭풍우와 같은 커다란 변화로 유발시키는 현상을 말하는 이 용어는 무엇일까요?","나비효과","잠자리효과","나방효과","매미효과",1,FALSE},// 7
	{"사회관계를 끊고 집안에만 틀어박혀 있어, '은둔형 외톨이'라고도 불리는 이것은 무엇일까요?","사스케","이타치","나루토","히키코모리",4,FALSE},// 8
	{"구장에서 난동을 부리는 무리들을 일컫는 말. 광적인 축구팬을 일컫는 말로도 쓰인다.","펄스건","훌리건","데모건","킹콩건",2,FALSE},// 9
	{"가족, 친척, 사회에서 격리돼 홀로 떨어져 살다가 아무도 모르게 홀로 죽어서 오랫동안 시신이 방치된 것을 의미하는 이 죽음은?","고독사","고약사","홀로사","방치사",1,FALSE},// 10
};
/*******************************************************************************************************/
//나라와 문화
quiz quizdata3[] = {
	{"세계에서 인구가 두 번째로 많은국가는 어디일까?","중국","인도","러시아","미국",2,FALSE},// 1
	{"대한민국의 전통의상은 한복입니다. 일본은 기모노 이구요. 그렇다면 중국의 전통의상은 무엇일까요?","치파오","치파사","치파육","치파일",1,FALSE},// 2
	{"세계에서 가장깊은 해구는?","오가사와해구","비티아즈 해구","마리아나 해구","챌린저 해구",3,FALSE},// 3
	{"다음 중 북유럽 국가가 아닌곳은?","노르웨이","덴마크","스웨덴","영국",4,FALSE},// 4
	{"다음 중 세계 2차대전당시 유태인을 학살한 히틀러가 속해있는 나라는?","이스라엘","독일","헝가리","핀란드",2,FALSE},// 5
	{"1922∼1991년 유라시아 대륙의 북부에 위치하는 여러 소비에트 사회주의공화국으로 구성된 최초의 사회주의 연방국가는?","소련","수련","유라시아연합","연방연합",1,FALSE},// 6
	{"전세계에서 유일한 휴전중인 국가로 언제든지 전쟁이 발발해도 이상하지 않은 국가는?","러시아","미국","대한민국","일본",3,FALSE},// 7
	{"사우디아라비아 출신의 '오사마 빈 라덴'이 조직한 국제 테러단체 이름은 무엇일까요?","마피아","삼합회","야쿠자","알 카에다",4,FALSE},// 8
	{"유럽의 중남부에 있는 큰 산계로 스위스, 프랑스, 이탈리아, 오스트리아에 걸쳐있다. 최고봉은 높이 4,807m인 몽블랑이다. 이산맥의 이름은?","알프스산맥","로키산맥","켈트산맥","블랑산맥",1,FALSE},// 9
	{"세계에서 손꼽히는 지진다발국으로, 수도는 산티아고(Santiago)이다. 태평양 연안에 위치하며 해안선의 길이는 6435㎞이다. 이나라는?","케이프타운","칠레","브라질","싱가포르",2,FALSE},// 10
};
/*******************************************************************************************************/
//국사와 세계사
quiz quizdata4[] = {
	{"허준이 지은 의학책은?","동의보감","동국여지승람","의학용어사전","국제의료행위분류",1,FALSE},// 1
	{"그리스로마신화에 나오는 신 중 미의 여신은?","헤라","비너스","메두사","미켈란젤로",2,FALSE},// 2
	{"중국 삼국시대 촉한의 정치가, 전략가. 유비에 의해 '삼고초려'의 예로 초빙됨","여포","장비","관우","제갈량",4,FALSE},// 3
	{"장영실이 만든 기구로 비의 량을 측정하기 위해 만든 것은?","측우기","앙부일구","자격루","거중기",1,FALSE},// 4
	{"나라를 새로 세울 때 공훈이 많은 신하를 의미하는 단어는?","시조","국회의원","개국공신","화랑",3,FALSE},// 5
	{"1919년 3월 1일을 기점으로 일본의 식민지 지배에 저항하여 전 민족이 일어난 항일독립운동으로 일제 강점기에 나타난 최대 규모의 민족운동이었으며, 제1차 세계대전 이후 전승국의 식민지에서 최초로 일어난 대규모 독립운동이기도 하다.","식민지운동","3.1운동","민족운동","일제강점기운동",2,FALSE},// 6
	{"1945년 우리나라가 일본으로부터 해방된 것을 기념하고, 임시정부 법통을 계승한 대한민국 정부수립을 축하하는 날은?","광복절","개천절","한글날","어버이날",1,FALSE},// 7
	{"조선 선조 25년(1592년)부터 31년(1598년)까지 두 차례에 걸쳐 우리나라를 침입한 일본과의 싸움","정유재란","병자호란","임진왜란","난나나란",3,FALSE},// 8
	{"18세기 중엽 영국에서 시작된 기술혁신과 이에 수반하여 일어난 사회·경제 구조의 변혁은?","산업혁명","시민혁명","기술혁명","경제혁명",1,FALSE},// 9
	{"사유재산제에 바탕을 두고 이윤 획득을 위해 상품의 생산과 소비가 이루어지는 경제체제는?","공산주의","민주주의","자본주의","개인주의",3,FALSE},// 10
};
/*******************************************************************************************************/
//과학
quiz quizdata5[] = {
	{"이산화탄소 등 온실기체에 의해 지구의 평균기온이 올라가는 현상은?","지구사우나화","지구온난화","지구열대아","지구핫썸머",2,FALSE},// 1
	{"어떤 물질속의 철의 성분은?","철분","리튬","바륨","탄소",1,FALSE},// 2
	{"지구가 속해있는 행성계이름은?","태양계","안드로메다","반계","이왕계",1,FALSE},// 3
	{"식물이 광합성을 할 때 사용하는 것은?","줄기","염록체","숨구멍","기도",2,FALSE},// 4
	{"지구 주변을 공전하는 위성은?","수성","금성","화성","달",4,FALSE},// 5
	{"염화나트륨을 주성분으로 하는 짠맛이 나는 흰 결정체","설탕","소금","코카인","요오드",2,FALSE},// 6
	{"생물은 생활환경에 적응하면서 단순한 것으로부터 복잡한 것으로 진화하며, 생존경쟁에 적합한 것은 살아남고 그렇지 못한 것은 도태된다는 학설","빅뱅설","진화론","생존론","도태론",2,FALSE},// 7
	{"미국의 우주비행사. 6·25전쟁 당시 제트기 조종사로 참전하였으며, 이후 미국항공우주국(NASA)에 들어갔다. 제미니 8호의 선장으로 아제나 위성과 최초의 도킹에 성공하고, 1969년 7월 20일 아폴로 11호로 인류 역사상 최초로 달에 착륙했다. 이사람의 이름은?","버락 오바마","도날드 트럼프","닐 암스트롱","미켈란젤로",3,FALSE},// 8
	{"최저 기온이 25℃ 이상인 무더운 밤을 뜻하는 용어는?","열대야","폭염","무더위","아지랑",1,FALSE},// 9
	{"일반적으로 수면위에서 발생하는 다양한 형태의 토네이도를 말한다.","소용돌이","돌개바람","쓰나미","용오름",4,FALSE},// 10
};
/*******************************************************************************************************/
//상식
quiz quizdata6[] = {
	{"나라를 운영하기위해 일반 시민들에게 걷는 돈을 뭐라고 하나요?","세금","새금","제금","재금",1,FALSE},// 1
	{"윷놀이에서 '도' 가 의미하는것은 무엇인가요?","말","돼지","양","뱀",2,FALSE},// 2
	{"우리몸에서 체온이 가장 낮은곳은 어디인가요?","이마","볼","귀","겨드랑이",3,FALSE},// 3
	{"식물의 뼈대가 긴 부분은?","줄기","잎","열매","꽃",1,FALSE},// 4
	{"지은이가 확실하지 않고 오랫동안 사람들에게 불려진 노래는?","민요","동요","가요","팝송",1,FALSE},// 5
	{"우주 공간을 비행할 수 있도록 만든 비행 물체는?","비행기","우주선","로켓","대륙간탄도미사일",2,FALSE},// 6
	{"남한과 북한을 구분하는 기준이 되는 선은?","35선","36선","37선","38선",4,FALSE},// 7
	{"2020년 대한민국의 대통령은?","이명박","문재인","김대중","노무현",2,FALSE},// 8
	{"석가탑,다보탑이 있는 경주의 절이름은?","불국사","해인사","능인사","조삼모사",1,FALSE},// 9
	{"한국의 대표이사와 같은 뜻으로, 기업을 대표하고 이사회의 결의를 집행하는 사람","ASD","CEO","QWE","AOMG",2,FALSE},// 10
};
/*******************************************************************************************************/
//사자성어
quiz quizdata7[] = {
	{"떨어지는 꽃과 흐르는 물이라는 뜻으로, 남녀 간 서로 그리워하는 애틋한 정을 이르는 말","낙화유수","구곡간장","전전반측","오매불망",1,FALSE},// 1
	{"자나깨나 잊지 못함","간담상조","오매불망","백아절현","막역지우",2,FALSE},// 2
	{"옛날 중국의 관중과 포숙처럼 친구 사이가 다정함을 이르는 말, 매우 다정하고 허물없는 친구사이","금란지교","막역지우","간담상조","관포지교",4,FALSE},// 3
	{"큰 그릇은 늦게 이루어진다는 뜻으로, 크게 될 인물은 오랜 공적을 쌓아 늦게 이루어짐을 이름","등요문","대기만성","입신양명","마부위침",2,FALSE},// 4
	{"눈을 비비고 다시 보며 상대를 대한다는 뜻으로, 다른 사람의 학식이나 업적이 크게 진보한 것을 말함","각곡유목","다기망양","괄목상대","혈성지공",3,FALSE},// 5
	{"남편이 주장하고 아내가 이에 따름. 가정에서의 부부 화합의 도리를 이르는 말임","세록치부","부창부수","균교임조","원수근화",2,FALSE},// 6
	{"'일을 맺은 사람이 풀어야 한다'는 뜻으로, 일을 저지른 사람이 그 일을 해결해야 한다는 말","교각살우","결자해지","이심전심","고장난명",2,FALSE},// 7
	{"모든 사물이 정도를 지나치면 도리어 안한 것만 못함이라는 뜻으로, 중용(中庸)을 가리키는 말","과유불급","수란지교","등화가친","문방사유",1,FALSE},// 8
	{"낮에는 농사짓고 밤에는 공부한다는 뜻으로, 바쁜 틈을 타서 어렵게 공부함을 이르는 말","문방사유","등화가친","한우충동","주경야독",4,FALSE},// 9
	{"준비가 있으면 근심이 없다라는 뜻으로, 미리 준비가 되어 있으면 뒷걱정이 없다는 뜻","유비무환","읍참마속","근주자적","위편삼설",1,FALSE},// 10
};
/*******************************************************************************************************/
//수도
quiz quizdata8[] = {
	{"대한민국의 수도는?","부산","서울","대전","대구",2,FALSE},// 1
	{"미국의 수도는?","워싱턴","뉴욕","오하이오","라스베이거스",1,FALSE},// 2
	{"일본의 수도는?","교토","시부야","훗카이도","도쿄",4,FALSE},// 3
	{"중국의 수도는?","광저우","베이징","우한","홍콩",2,FALSE},// 4
	{"영국의 수도는?","옥스포드","캠브릿지","런던","맨체스터",3,FALSE},// 5
	{"호주의 수도는?","멜버른","시드니","캔버라","브리즈번",3,FALSE},// 6
	{"베트남의 수도는?","하노이","다낭","호치민","깐토라",1,FALSE},// 7
	{"독일의 수도는?","뮌헨","베를린","하멜른","브레멘",2,FALSE},// 8
	{"멕시코의 수도는?","멕시코시티","에카테펙","티후아나","몬테레이",1,FALSE},// 9
	{"캐나다의 수도는?","오타와","퀘벡","토론토","몬트리올",1,FALSE},// 10
};
/*******************************************************************************************************/
//신조어
quiz quizdata9[] = {
	{"사귀다의 전 단계, 썸탄다를 대체하는 새로운 용어는?","일귀다","이귀다","삼귀다","오귀다",3,FALSE},// 1
	{"진짜라는 뜻을 의미하는 신조어는?","찐","진","짜","찌",1,FALSE},// 2
	{"꾸민 듯 안꾸민듯한 스타일을 의미하는 신조어는?","꾸민안꾸민","꾸안구","꾸","뀨뀨",2,FALSE},// 3
	{"멍청하게 굴지 않았다면 쓰지 않았어도 됐을 돈을 뜻하는 신조어는?","멍청비용","멍청소비","멍청낭비","멍청돈",1,FALSE},// 4
	{"뇌 + 오피셜의 합성어로 검증된 공식정보가 아닌 자신의 생각이나 논리를 검증된 것처럼 이야기 하는 것을 의미하는 신조어는?","뇌지컬","망상","픽션","뇌피셜",4,FALSE},// 5
	{"개인취향존중의 줄임말로 각 개인의 취향을 모두 존중해주는 뜻을 의미하는 신조어는?","개취존","개인존","개향존","개취중",1,FALSE},// 6
	{"얼어죽더라고 아이스 음료를 마시는 사람을 뜻하는 신조어는?","냉동아","얼죽아","얼이스","죽이스",2,FALSE},// 7
	{"졌지만 잘싸웠다의 줄임말로 결과는 안좋아도 열심히 한 과정을 인정해주고 응원해주는 신조어는?","졌잘싸","루즈벗윈","위캔윈","잘싸웠다",1,FALSE},// 8
	{"만나서 반갑고 잘 부탁드립니다의 줄임말은?","만반부탁","반잘부탁","만반부탁","만반잘부",4,FALSE},// 9
	{"혼란한 틈을 타서 무엇인가를 한다 라는 것을 뜻하는 신조어는?","혼란틈","혼틈","흔틈","한틈",2,FALSE},// 10
};
/*******************************************************************************************************/
//넌센스
quiz quizdata10[] = {
	{"왕이넘어졌다를 두글자로하면?","킹콩","킹꽁","왕콩","왕쿵",1,FALSE},// 1
	{"왕이궁에돌아가기 싫을 때 하는 말은?","궁싫엉","궁시렁","노왕궁","이왕표",2,FALSE},// 2
	{"세상에서 가장 가난한 왕은?","거지욍","왕초","최저임금","사도세자",3,FALSE},// 3
	{"웃는 바나나를 4글자로 하면?","풋바나나","바나나풋","킥바나나","바나나킥",4,FALSE},// 4
	{"형제가 싸울 때 부모님이 동생편만 들어주는 세상은?","형편없는세상","아우최고인세상","바람직한세상","옳바른세상",1,FALSE},// 5
	{"병아리가 항상 먹는 약은?","항우울제","삐약","개보린","마데카솔",2,FALSE},// 6
	{"달걀이 버는 돈을 네글자로 하면?","닭걀머니","계란머니","에그머니","삐약머니",3,FALSE},// 7
	{"가수 비의 매니저가 하는 일은?","1일1깡","1일2깡","1일3깡","비만관리",4,FALSE},// 8
	{"시험만 보면 0점을 받는 연예인은?","비","백지영","나얼","박효신",2,FALSE},// 9
	{"세상에서 제일 쉬운 숫자는?","190000","2.1","3.2","4.3",1,FALSE},// 10
};
/*******************************************************************************************************/
int main(void) {
	system("mode con cols=100 lines=30 | title 재미있는 퀴즈게임");//콘솔창 크기와 제목
	system("color 9f");//배경과 글자색
	int answer;//답
	player user[3];//플레이어 정보
	player winner;//승자
	int topic;	//주제선택값
	int score = 0;	//점수값
	int p; //플레이어 수값
	int yn;		//yes나 no의 선택값
	int quiznum;//퀴즈번호
	randomize();
	/*******************************************************************************************************/
main:
	printf("\n\n\n");
	printf("                           $$  $$              $$    $$$$$   $$    $$              \n");
	printf("               $$$$$$$$$   $$  $$    $$$$$$$$  $$   $$   $$  $$    $$                         \n");
	printf("                  $$       $$  $$    $$    $$  $$   $$   $$  $$    $$$$$$$$$                   \n");
	printf("                 $$$$      $$$$$$    $$    $$  $$    $$$$$   $$                     \n");
	printf("                $$  $$     $$  $$    $$$$$$$$  $$            $$  $$$$$$$$$$$$$                    \n");
	printf("               $$    $$    $$  $$              $$      $$   $$     $$              \n");
	printf("                           $$  $$              $$     $$$$ $$$$    $$              \n");
	printf("                                                     $$  $$$  $$   $$$$$$$$$         \n");
	printf("                                                                           \n");
	printf("                 $$$$$$$$$  $$                    $$$$$$$$$$$$               $$    \n");
	printf("                        $$  $$     $$$$$$$$$$        $$  $$      $$$$$$$$$$  $$   \n");
	printf("                 $$$$$$$$$  $$         $$         $$$$$$$$$$$$           $$  $$              \n");
	printf("                        $$  $$        $$$$                              $$   $$ \n");
	printf("                $$$$$$$$$$$$$$$      $$  $$      $$$$$$$$$$$$$$        $$    $$               \n");
	printf("                     $$     $$      $$    $$           $$             $$     $$         \n");
	printf("                     $$     $$                     $$$$$$$$$$        $$      $$           \n");
	printf("                     $$     $$   $$$$$$$$$$$$$             $$       $$       $$               \n");
	printf("                     $$     $$                     $$$$$$$$$$      $$        $$     \n");
	printf("                                                   $$                        $$  \n");
	printf("                                                   $$$$$$$$$$                   \n");
	printf("\n\n제작자:\n");
	printf("플레이어 수를 입력해주세요.(최대 4명)\n");
	/*******************************************************************************************************/
back1:
	scanf("%d", &p);
	if (p > 4) {
		printf("플레이어 수가 너무 많습니다.\n다시 입력해주세요.\n");
		goto back1;
	}
	else if (p < 1) {
		printf("플레이어 수가 너무 적습니다.\n다시 입력해주세요\n");
		goto back1;
	}
	system("cls");
	for (int i = 0; i < p; i++) {
		gotoxy(30, 2 + 2 * i);
		printf("플레이어의 이름을 입력해주세요\n");
		gotoxy(30, 3 + 2 * i);
		scanf("%s", &user[i].name);
	}
	system("cls");
	for (int i = 0; i < p; i++) {
	beginning:
		printf("%s의 차례입니다.\n", user[i].name);
		gotoxy(30, 2); printf("주제를 보고 선택해 번호를 입력해주세요.\n");
		gotoxy(35, 4); printf("1.시사\n");
		gotoxy(35, 5); printf("2.사회와 경제\n");
		gotoxy(35, 6); printf("3.나라와 문화\n");
		gotoxy(35, 7); printf("4.국사와 세계사\n");
		gotoxy(35, 8); printf("5.과학\n");
		gotoxy(35, 9); printf("6.상식\n");
		gotoxy(35, 10); printf("7.사자성어\n");
		gotoxy(35, 11); printf("8.수도\n");
		gotoxy(35, 12); printf("9.신조어\n");
		gotoxy(35, 13); printf("10.넌센스\n");
		gotoxy(35, 14); scanf("%d", &topic);
		if (topic > 12) {
			gotoxy(35, 17);
			printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
			Sleep(1000);
			system("cls");
			goto beginning;
		}
		system("cls");
		/*문제제출 및 정답입력**************************************************************************************/
		if (topic == 1) {
			if (quizdata1[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("시사를 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata1) / sizeof(quizdata1[0]));
				} while (quizdata1[quiznum].already == TRUE);
				quizdata1[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata1[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata1[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop1:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata1[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop1;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata1[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata1[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop1;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata1[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
		if (topic == 2) {
			if (quizdata2[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("사회와 경제를 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata2) / sizeof(quizdata2[0]));
				} while (quizdata2[quiznum].already == TRUE);
				quizdata2[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata2[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata2[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop2:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata2[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop2;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다.\n");
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata2[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop2;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다.\n");
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
		if (topic == 3) {
			if (quizdata3[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("나라와 문화를 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata3) / sizeof(quizdata3[0]));
				} while (quizdata3[quiznum].already == TRUE);
				quizdata3[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata3[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata3[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop3:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata3[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop3;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata3[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata3[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop3;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata3[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
		if (topic == 4) {
			if (quizdata4[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("국사와 세계사를 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata4) / sizeof(quizdata4[0]));
				} while (quizdata4[quiznum].already == TRUE);
				quizdata4[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata4[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata4[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop4:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata4[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop4;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata4[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata4[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop4;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata4[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
		if (topic == 5) {
			if (quizdata5[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("과학을 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata5) / sizeof(quizdata5[0]));
				} while (quizdata5[quiznum].already == TRUE);
				quizdata5[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata5[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata5[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop5:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata5[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop5;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata5[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata5[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop5;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata5[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
		if (topic == 6) {
			if (quizdata6[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("상식을 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata6) / sizeof(quizdata6[0]));
				} while (quizdata6[quiznum].already == TRUE);
				quizdata6[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata6[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata6[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop6:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata6[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop6;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata6[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata6[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop6;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata6[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
		if (topic == 7) {
			if (quizdata7[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("사자성어를 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata7) / sizeof(quizdata7[0]));
				} while (quizdata7[quiznum].already == TRUE);
				quizdata7[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata7[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata7[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop8:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata7[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop8;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata7[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata7[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop8;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata7[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
		if (topic == 8) {
			if (quizdata8[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("수도를 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata8) / sizeof(quizdata8[0]));
				} while (quizdata8[quiznum].already == TRUE);
				quizdata8[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata8[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata8[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop9:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata8[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop9;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata8[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata8[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop9;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata8[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
		if (topic == 9) {
			if (quizdata9[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("신조어를 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata9) / sizeof(quizdata9[0]));
				} while (quizdata9[quiznum].already == TRUE);
				quizdata9[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata9[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata9[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop10:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata9[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop10;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata9[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata9[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop10;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata9[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
		if (topic == 10) {
			if (quizdata10[1].already == TRUE) {
				gotoxy(30, 2);
				printf("이미 푼 문제입니다.\n");
				gotoxy(30, 3);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(2000);
				system("cls");
				goto beginning;
			}
			gotoxy(30, 1);
			printf("넌센스를 선택하셨습니다.\n");
			for (int k = 0; k < 10; k++) {
				do
				{
					quiznum = random(sizeof(quizdata10) / sizeof(quizdata10[0]));
				} while (quizdata10[quiznum].already == TRUE);
				quizdata10[quiznum].already = TRUE;
				gotoxy(20, 2);
				printf("문제%d. %s\n", k + 1, quizdata10[quiznum].question);
				for (int j = 0; j < 4; j++) {
					gotoxy(30, j + 4);
					printf("%d. %s\n", j + 1, quizdata10[quiznum].Case[j]);
				}
				gotoxy(30, 8);
				printf("답을 입력하세요.\n");
			loop12:
				gotoxy(30, 9);
				scanf("%d", &answer);
				if (k == 9) {
					if (answer == quizdata10[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop12;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata10[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 점수화면으로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				else {
					if (answer == quizdata10[quiznum].answer) {
						gotoxy(30, 10);
						printf("정답입니다.\n");
						score += 1;
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
					else if (answer > 4) {
						gotoxy(30, 10);
						printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
						goto loop12;
					}
					else {
						gotoxy(30, 10);
						printf("틀렸습니다. 정답은 %d입니다.\n", quizdata10[quiznum].answer);
						for (int l = 5; l > 0; l--) {
							gotoxy(30, 17 - l);
							printf("%d초 후 다음 문제로 넘어갑니다.\n", l);
							Sleep(1000);
						}
					}
				}
				system("cls");
			}
		}
		/*******************************************************************************************************/
	back3:
		gotoxy(30, 2);
		printf("%d점입니다.\n", score * 10);

		if (i == p - 1) {
			gotoxy(30, 3);
			printf("계속하시겠습니까?\n");
			gotoxy(30, 4);
			printf("1.yes 2.no\n");

			gotoxy(30, 5);
			scanf("%d", &yn);
			if (yn == 1) {
				gotoxy(30, 6);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(3000);
				system("cls");
				goto beginning;
			}
			else if (yn == 2) {
				gotoxy(30, 6);
				printf("승자 확인 화면으로 넘어갑니다.\n");
				user[i].s = score;
				score = 0;
				Sleep(3000);
				system("cls");
			}
			else {
				gotoxy(30, 6);
				printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
				Sleep(1000);
				system("cls");
				goto back3;
			}
		}
		else {
			gotoxy(30, 3);
			printf("계속하시겠습니까?\n");
			gotoxy(30, 4);
			printf("1.yes 2.no\n");
			gotoxy(30, 5);
			scanf("%d", &yn);
			if (yn == 1) {
				gotoxy(30, 6);
				printf("주제 선택으로 돌아갑니다.\n");
				Sleep(3000);
				system("cls");
				goto beginning;
			}
			else if (yn == 2) {
				gotoxy(30, 6);
				printf("다음 플레이어로 넘어갑니다.\n");
				user[i].s = score;
				score = 0;
				Sleep(3000);
				system("cls");
			}
			else {
				gotoxy(30, 6);
				printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
				Sleep(1000);
				system("cls");
				goto back3;
			}
		}
		/*******************************************************************************************************/
	}
back5:
	for (int i = 0; i < p; i++) {
		gotoxy(30, 2 + i);
		printf("%s %d\n", user[i].name, user[i].s * 10);
		if (i == 0) {
			winner = user[i];
		}
		else {
			if (winner.s < user[i].s) {
				winner = user[i];
			}
			else {
				winner = winner;
			}
		}
	}
	gotoxy(30, 7);
	printf("승자는 %s입니다.", winner.name);
	gotoxy(30, 8);
	printf("종료하시겠습니까?");
	gotoxy(30, 9);
	printf("1.yes 2.no\n");

	gotoxy(30, 10);
	scanf("%d", &yn);
	if (yn == 1) {
		gotoxy(30, 11);
		printf("프로그램을 종료합니다.\n");
		Sleep(3000);
		system("cls");
	}
	else if (yn == 2) {
		gotoxy(30, 11);
		printf("메인화면으로 돌아갑니다.\n");
		Sleep(3000);
		system("cls");
		goto main;
	}
	else {
		gotoxy(30, 11);
		printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
		Sleep(1000);
		system("cls");
		goto back5;
	}
	return 0;
}