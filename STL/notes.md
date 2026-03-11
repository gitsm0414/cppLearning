<STL introduction with vector>
C-array의 단점: 
static array의 경우 컴파일 되기 전에 배열의 크기를 알아야한다.
만약, 동적으로 할당할 경우 malloc/free/new/delete등 신경써주어야 한다.

이때 벡터를 사용하면 동적할당을 신경쓰지 않으면서도 크기가 마음대로 변경되는 배열같은 구조를 이용할 수 있다.

벡터의 다양한 멤버함수 참고: https://www.cplusplus.com/reference/vector/vector/

알아야할 멤버함수
-push_back()
-size()
-capacity()
현재 할당된 메모리 크기를 리턴한다. capacity >= size이다. 공간이 꽉차게되면 자동적으로 capacity가 늘어난다. 
보통의 경우 2배씩. GCC의 경우 2배이다.
-reserve()
이 함수를 통해 capacity를 미리 설정할 수 있다. 예를들어 v.reserve(32); v.reserve(v.size()+50);
-resize(n)
벡터의 size를 n으로 맞추는 작업, 늘려야 하면 뒤에 0 또는 빈 객체로 채워놓고, 줄여야 하면 n번째 뒷 요소들은 모두 삭제한다. 
단 기존 capacity가 줄어들진 않는다.
-clear()
벡터의 size = 0 이 된다. 하지만 기존 capacity는 변함이 없다.

-rbegin()
벡터의 가장 마지막 요소를 가리킴.
-rend()
첫번째 요소의 앞(전) 공간을 가리킴.
>> vector<int>::reverse_iterator r_it; 이런 식으로 사용한다. 
이때 r_it++;는 반대방향인 뒤->앞이 된다. 말그대로 reverse가 이미 된 것이니 헷갈리지 않기.


<Standard template library>
Four components: containers, adaptors, iterators, algorithms

<simple containers>
-pair: 두개의 데이터를 하나로 묶는다. 예) std::pair<int, string>
-tuple: 세 개 이상의 데이터를 묶을 때 사용한다. 

<sequence containers>
데이터가 삽입된 순서를 유지하는 선형구조

-vector: 동적배열 >> random access 가 매우 빠름 O(1). 중간에 삽입/삭제는 데이터를 밀어야해서 느림
-list: 이중 연결리스트 >> 중간 삽입/삭제는 매우 빠르나, random access는 O(N)
-deque: 양방향 큐 >> 앞, 뒤에서 삽입/삭제가 빠름, 내부구조가 복잡해 vector보다 살짝 느림.

<associative containers>
데이터를 특정 규칙에 따라 정렬해서 저장함. 데이터가 항상 정렬상태를 유지하기 때문에 검색/삽입/삭제 모두 O(logN)

-set: 중복없는 값들의 집합
예) set<char> s; set<char>::iterator t; 
s.insert('a'); s.erase('a');
if(s.find('a') == s.end()) //s 안에 'a'가 없다면... 이라는 뜻

-map: key-value, 쌍으로 저장
예) map<string, string> m; map<string, string>::iterator t;
m.[key1] = value1;
m.insert(pair<string, string>(key2, value2));
...
if(m.find(key_var) == m.end()) //m 안에 key_var에 대응하는 키가 없다면... 이라는 뜻

for(t = m.begin(); t != m.end(); t++){
    cout << t->first << ' ' << t->second << endl;
}
>>why? map은 내부적으로 데이터를 std::pair<const key, value> 형태로 저장한다. 따라서 iterator t로
접근하려면 -> 연산자를 사용해서 t->first, t->second로 나타내야한다.

-multiset, multimap: 중복을 허용한 set, map 

정렬되지 않은 컨테이너
-unordered_map: 정렬은 안됐지만, 평균적으로 탐색속도가 O(1)로 매우 빠름. 해시테이블을 이용하기 때문임.
데이터가 많을 때 성능 최적화용으로 자주 쓰임.

<container adaptors>
기존 컨테이너를 재활용해서 버그가 적고 구현이 매우 빠르다.
-stack > deque 기반
-queue > deque 기반
-priority_queue > vector 기반
기본적으로 이렇게 정해져있지만 의도적으로 기반 컨테이너를 바꿀 수도 있다.


실전 팁: 무엇을 사용해야 할까?

기본적으로는 vector를 쓰세요.           가장 메모리 효율적이고 빠릅니다.
중간에 넣고 빼는 게 많다면?             list를 고민하세요.
검색을 엄청 많이 해야 한다면?           unordered_map을 고려하세요.
데이터가 항상 정렬되어 있어야 한다면?    map이나 set을 고려하세요.



<iterator>
>>STL containers/adaptors를 가리키는 pointer의 일반화

포인터 처럼 ++, --, ==, !=, *가 가능하다. 마찬가지로 
예를들어 vector<int> v; vector<int>::iterator t;라면, 
v[i], t[i], *(t+i)는 같은 결과의 서로 다른 세가지 표현방법이다.

.begin(), .end()의 활용: 벡터를 예로들면, 첫번째 원소의 위치와 마지막 바로 하나 다음 위치를 리턴한다. 이를 이터레이터의 값으로 넣어줄 수 있다.



벡터 등 random access가능한 iterator의 사용예시
(++, --, +n, -n, [n] 가능하다. 반면 list는 ++, --만, forward_list는 ++만 가능하다.)

vector<int>::iterator it = v.end();

//마지막 원소를 0으로 만든다. 이때 v.end()는 마지막에서 하나 뒤인 즉, 정의되지 않은 공간을 가리키므로 --it를 이용해야한다.
*--it = 0;

//아래 코드는 무엇을 의미할까? it[-2] 는 *(it + (-2))와 같다. 
//현재 it는 마지막 원소를 가리키므로 아래 코드는 v의 마지막에서 세번째 값을 0으로 지정한것과 같다.
it[-2] = 0;


STL(lab)세션에 ex2와 assignment는 이전까지의 모든 pdf를 다 복습하고 나서 다시 해보기로.