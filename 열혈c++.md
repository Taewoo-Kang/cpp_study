---


---

<h1 id="c로의-전환">C++로의 전환</h1>
<h2 id="c언어-기반의-c-1">C언어 기반의 C++ 1</h2>
<h3 id="함수-오버로딩">함수 오버로딩</h3>
<p>함수호출 시 전달되는 인자를 통해서 호출하고자 하는 함수의 구분이 가능하기 때문에 <em>매개변수의 선언형태가 다르다면</em> <strong>동일한 이름의 함수정의를 허용</strong></p>
<h3 id="매개변수의-디폴트-값">매개변수의 디폴트 값</h3>
<p>매개변수의 디폴트 값은 함수의 원형 선언에만 위치시켜야 한다.</p>
<h3 id="이름공간namespace">이름공간(namespace)</h3>
<p><code>std::cout</code> — 이름공간 std에 선언된 cout<br>
참고로, 동일한 이름공간에 정의된 함수를 호출할 때에는 이름공간을 명시할 필요가 없다.</p>
<blockquote>
<p>함수내에서 동일한 이름의 지역변수 대신 <strong>전역변수에 접근</strong>하려면 범위지정 연산자 사용! (ex. <code>::val</code>)</p>
</blockquote>
<h2 id="c언어-기반의-c-2">C언어 기반의 C++ 2</h2>
<h3 id="참조자reference">참조자(Reference)</h3>
<p>참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름 (복사하지 않고 그대로 사용)</p>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token keyword">int</span> <span class="token operator">*</span>ptr <span class="token operator">=</span> <span class="token operator">&amp;</span>num1<span class="token punctuation">;</span> <span class="token comment">// num1의 주소값을 반환해서 포인터에 저장</span>
<span class="token keyword">int</span> <span class="token operator">&amp;</span>num2 <span class="token operator">=</span> num1<span class="token punctuation">;</span> <span class="token comment">// num1에 대한 참조자 num2를 선언</span>
</code></pre>
<p>참조자는 무조건 선언과 동시에 변수를 참조하도록 해야한다.(리터럴x 단, const 참조자는 가능)<br>
포인터 변수도 변수이기 때문에 참조자의 선언이 가능</p>
<p><strong>Call-by-reference</strong><br>
주소값을 전달받아서 함수 외부에 선언된 변수에 접근하는 형태의 함수호출</p>
<blockquote>
<p>const 참조자를 이용하여 함수 내에서 값 변경이 없음을 명시! — 함수 원형만 보고 판단 가능</p>
</blockquote>
<p><strong>반환형이 참조형</strong>일 경우 반환값을 무엇으로 저장하느냐에 따라 결과의 차이가 있음(참조자가 아닌 일반변수를 선언해서 반환값을 저장할수도) - p.85</p>
<blockquote>
<p>지역변수를 참조형으로 반환하는 일은 없어야한다!</p>
</blockquote>
<h3 id="new--delete">new &amp; delete</h3>
<p>동적할당 관련 — 객체 생성에는 반드시!<br>
new 연산자를 이용해서 할당된 메모리 공간에도 <em><strong>참조자의 선언</strong></em> 이 가능</p>
<h1 id="객체지향의-도입">객체지향의 도입</h1>
<h2 id="클래스의-기본">클래스의 기본</h2>
<h3 id="클래스와-객체">클래스와 객체</h3>
<p>구조체는 연관있는 데이터를 묶을 수 있는 문법적 장치 — 연관있는 데이터를 묶으면, 프로그램의 구현 및 관리가 용이</p>
<p>함수의 원형을 클래스 안에 두고 정의를 클래스 밖으로 — 정의를 밖으로 빼내도 클래스의 일부이기 때문에 함수내 private에 접근 가능</p>
<p>헤더파일(.h)에 <strong>클래스의 선언</strong>, 소스파일(.cpp)에 <strong>클래스의 정의</strong>를 저장 (단, 인라인 함수는 헤더파일에)</p>
<h3 id="객체지향-프로그래밍의-이해">객체지향 프로그래밍의 이해</h3>
<p><strong>객체</strong> : 데이터(변수) + 기능(함수)<br>
<strong>객체지향 프로그래밍</strong> — 현실에 존재하는 사물과 대상, 그리고 그에 따른 행동을 있는 그대로 실체화시키는 형태의 프로그래밍</p>
<p>클래스의 객체 생성방식</p>
<pre class=" language-cpp"><code class="prism  language-cpp">FruitSeller seller<span class="token punctuation">;</span>
FruitSeller <span class="token operator">*</span>objPtr <span class="token operator">=</span> <span class="token keyword">new</span> FruitSeller<span class="token punctuation">;</span> <span class="token comment">// 동적 할당</span>
</code></pre>
<h2 id="클래스의-완성">클래스의 완성</h2>
<h3 id="정보은닉">정보은닉</h3>
<p>해당 변수에 접근하는 함수를 별도로 정의하여 안전한 형태로 멤버변수의 접근을 유도하는 것!</p>
<p>const 함수 — <strong>멤버변수</strong>에 저장된 값을 변경 x</p>
<blockquote>
<p>const 함수 내에서는 const가 아닌 함수의 호출이 제한</p>
</blockquote>
<h3 id="캡슐화">캡슐화</h3>
<h3 id="생성자와-소멸자">생성자와 소멸자</h3>
<p><strong>생성자</strong></p>
<ul>
<li>클래스의 이름과 함수 이름 동일</li>
<li>반환형 선언 x</li>
</ul>
<p><strong>객체의 생성과정</strong></p>
<ol>
<li>메모리 공간의 할당</li>
<li>이니셜라이저를 이용한 객체의 초기화</li>
<li>생성자의 몸체 부분 실행</li>
</ol>
<pre class=" language-cpp"><code class="prism  language-cpp">Line<span class="token operator">::</span><span class="token function">Line</span><span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">int</span> <span class="token operator">&amp;</span>x1<span class="token punctuation">,</span> <span class="token keyword">const</span> <span class="token keyword">int</span> <span class="token operator">&amp;</span>x2<span class="token punctuation">)</span> <span class="token operator">:</span> <span class="token function">left</span><span class="token punctuation">(</span>x1<span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">Right</span><span class="token punctuation">(</span>x2<span class="token punctuation">)</span> <span class="token punctuation">{</span><span class="token punctuation">}</span>
</code></pre>
<p>이니셜라이저를 이용하면 객체, 멤버변수, const 상수 초기화 가능 + 참조자를 멤버변수로 선언 가능</p>
<p><strong>소멸자</strong></p>
<ul>
<li>클래스의 이름 앞에 '~'가 붙은 형태의 이름</li>
<li>반환형 선언 x</li>
<li>매개변수는 void형으로 선언되어야 하므로 <strong>오버로딩, 디폴트값 불가</strong></li>
</ul>
<h3 id="클래스와-배열-그리고-this-포인터">클래스와 배열 그리고 this 포인터</h3>
<p><strong>객체배열</strong> — 생성자 별도 명시 불가능(인자 전달 x) -&gt; 일일이 초기화!</p>
<blockquote>
<p>객체 포인터를 이용해서 주소값 저장도 가능</p>
<pre class=" language-cpp"><code class="prism  language-cpp">Person <span class="token operator">*</span> parr<span class="token punctuation">[</span><span class="token number">3</span><span class="token punctuation">]</span><span class="token punctuation">;</span> <span class="token comment">// 포인터 배열 선언</span>
parr<span class="token punctuation">[</span><span class="token number">0</span><span class="token punctuation">]</span> <span class="token operator">-</span><span class="token operator">&gt;</span> <span class="token function">ShowPersonInfo</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">// 구조체 포인터의 멤버 접근</span>
</code></pre>
</blockquote>
<p><strong>this 포인터</strong> — 객체 자신의 주소값을 의미</p>
<blockquote>
<p>객체 포인터를 가지고는 지역변수에 접근이 불간능하다는 특성을 활용하여 매개변수와 멤버변수의 이름을 똑같이 해서 사용 가능</p>
</blockquote>
<p><em>Self Reference</em> — 반환형을 참조형으로 하여 객체 자신의 참조값 반환</p>
<h2 id="복사-생성자">복사 생성자</h2>
<h3 id="깊은-복사와-얕은-복사">깊은 복사와 얕은 복사</h3>
<p><strong>디폴트 복사 생성자</strong> -&gt; 멤버 대 멤버 단순 복사 -&gt; 하나의 문자열을 두 객체가 동시 참조 =&gt; <mark><strong>소멸자 실행에 문제 발생</strong></mark></p>
<h3 id="복사-생성자의-호출-시점">복사 생성자의 호출 시점</h3>

