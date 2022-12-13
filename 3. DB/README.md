
☞ DFD (Data Flow Diagram)
<br>
쉽게 말해 자료의 출발지와 목적지를 그림으로 표시한 것이다.<br>
<br>
'데이터 흐름도' 또는 '자료 흐름도' 라고도 한다.<br>

☞ DFD의 구성요소<br>

DFD의 구성요소 4가지 = 프로세스, 데이터흐름, 데이터저장소, 외부엔티티

1. 프로세스(Process) - 원(Bubble)

입력되는 데이터를 원하는 데이터로 변환하여 출력시키기 위한 과정이다.
도형적 표기형태는 원(Bubble)과 원안의 이름으로 표현한다.
원안에 기록하는 이름은 프로세스가 수행하는 일 또는 프로세스를 수행하는 행위자를 기술한다.
자체적으로는 데이터를 생성할 수 없고 항상 입력되는 데이터가 있어야 한다.
항상 새로운 가치를 부가해야 한다.

2. 데이터흐름(Data Flow) - 화살표

DFD의 구성요소간 인터페이스를 나타낸다.
대부분의 데이터흐름은 프로세스 사이를 연결하지만, 데이터 저장소(Data Store)로부터의 데이터흐름을 나타내기도 한다.
명칭이 부여거나 부여되지 않은 화살표로 표시한다. 단, 후속작업의 참조를 위해 되도록 명칭이 부여되는 것이 바람직하다.
서로 다른 데이터 흐름에는 동일한 이름을 부여하지 않는다.

3. 데이터저장소(Data Store) - 두 평행선 

추후 엑세스를 위해 데이터를 저장하는 수동적 객체를 말한다.
액터와는 달리 자신의 액션을 취하지 않으며 데이터 저장이나 엑세스 요구에 반응할 뿐이다.
데이터저장소(Data Store)는 저장되어 있는 정보 집합이다.
데이터저장소는 테이프, 디스크, 카드 데이타, 캐비넷의 인덱스화일 등일 수도 있으며, 때로는 휴지통일 수도 있다.
데이터저장소는 단순한 데이터의 저장을 나타내는 것이지 데이터의 변동을 표시하는 것은 아니다.
데이터흐름을 표시함으로서 데이터의 입출력을 나타낸다.
표기법은 단순하게 두 개의 직선 즉, 평행선으로 나타내고, 평행선 안에 데이터저장소의 명칭을 부여한다.

4. 외부엔티티(External Entity) - 사각형

프로세스 처리과정의 데이터발생의 시작 및 종료를 나타낸다.
어떤 기업의 내적인(Inside) 엔티티는 관리, 부서, 기능, 시스템등을 포함하며, 기업 외적인(Outside) 엔티티는 고객, 거래처, 공공기관, 외부시스템등을 포함한다.
데이터 흐름도상에서 프로세스(Process)와의 상호관련성을 표시하며, 일반적으로 DFD 범위 밖에 사각형 형태로 표시한다.
액터는 데이터를 생성, 소비 함으로서 데이터 흐름도를 주도하는 활성 객체이다.
액터는 데이터 흐름도의 입력과 출력에 붙는다. 즉, 흐름도의 경계에 놓이게 되며, 소스(source)나 싱크(sink)로서 데이터의 흐름을 중단시킨다.
예를 들어, 프로그램의 사용자, 써모셋(thermostat), 서보 모터 등이다. 

DFD 그리는법

1. 업무를 분석하여 프로세스에 대한 모든 입출력 데이터흐름을 식별한다. 
2. 흐름상 필요하거나 제공되어야 할 외부엔티티를 정의한다.
3. 입력으로부터 출력으로, 출력으로부터 입력으로, 또는 중간 지점부터의 데이터흐름을 식별한다.
4. 모든 접속관계 데이터흐름에 주의깊게 명칭(혹은 자료 내역)을 부여한다.
5. 프로세스에 대해 입출력 데이터흐름의 명칭에 따라 이름을 부여한다.
6. 프로세스에 관련된 데이터저장소를 정의한다.
7. 검토하고 작성한다.