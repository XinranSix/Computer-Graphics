## 一、ES 6 新特性

### 1.1 `let` 关键字

let 关键字用来声明变量，使用 let 声明的变量有几个特点：

1.  不允许重复声明；
2.  块级作用域；
3.  不存在变量提升；
4.  不影响作用域链。

应用场景：以后声明变量使用 let 就对了。

### 1.2 `const` 关键字

const 关键字用来声明常量，const 声明有以下特点：

1.  声明必须赋初始值；
2.  标识符一般为大写；
3.  不允许重复声明；
4.  值不允许修改；
5.  块级作用域。

注意: 对象属性修改和数组元素变化不会出发 const 错误。

应用场景：声明对象类型使用 const，非对象类型声明选择 let。

### 1.3 变量的解构赋值

ES 6 允许按照一定模式，从数组和对象中提取值，对变量进行赋值，这被称为解构赋值。

```js
//数组的解构赋值
const arr = ['张学友', '刘德华', '黎明', '郭富城'];
let [zhang, liu, li, guo] = arr;

      //对象的解构
const zhao = {
	name: '赵本山',
	age: '不详',
	xiaopin: function(){
		console.log("我可以演小品");
	}
};

let {name, age, xiaopin} = zhao;


//复杂解构
let wangfei = {
	name: '王菲',
	age: 18,
	songs: ['红豆', '流年', '暧昧', '传奇'],
	history: [
		{ name: '窦唯' },
		{ name: '李亚鹏' },
		{ name: '谢霆锋' }
	]
};
let { songs: [one, two, three], history: [first, second, third] } = wangfei;
```

注意：频繁使用对象方法、数组元素，就可以使用解构赋值形式。

### 1.4 模板字符串

模板字符串（template string）是增强版的字符串，用反引号（\`）标识，特点：

1.  字符串中可以出现换行符；
2.  可以使用 `${xxx}` 形式输出变量。

```js
//内容中可以直接出现换行符
let str = `<ul>
			<li>沈腾</li>
			<li>玛丽</li>
			<li>魏翔</li>
			<li>艾伦</li>
			</ul>`;
//变量拼接
let lovest = '魏翔';
let out = `${lovest}是我心目中最搞笑的演员!!`;
console.log(out);
```

### 1.5 简化对象写法

ES 6 允许在大括号里面，直接写入变量和函数，作为对象的属性和方法。这样的书写更加简洁。

```js
//ES6 允许在大括号里面，直接写入变量和函数，作为对象的属性和方法。
//这样的书写更加简洁
let name = '尚硅谷';
let change = function() {
	console.log('我们可以改变你!!');
}

const school = {
	name,
	change,
	improve() {
		console.log("我们可以提高你的技能");
	}
}
console.log(school);
```

注意：对象简写形式简化了代码，所以以后用简写就对了。

### 1.6 箭头函数

ES 6 允许使用「箭头」（`=>`）定义函数。

```js
**
* 1. 通用写法
*/
let fn = (arg1, arg2, arg3) => {
	return arg1 + arg2 + arg3;
}
```

箭头函数的注意点：

1.  如果形参只有一个，则小括号可以省略；
2.  函数体如果只有一条语句，则花括号可以省略，函数的返回值为该条语句的执行结果；
3.  箭头函数 this 指向声明时所在作用域下 this 的值；
4.  箭头函数不能作为构造函数实例化；
5.  不能使用 arguments。

```js
/**
* 2. 省略小括号的情况
*/
let fn2 = num => {
	return num * 10;
};

/**
* 3. 省略花括号的情况
*/
let fn3 = score => score * 20;

/**
* 4. this 指向声明时所在作用域中 this 的值
*/
let fn4 = () => {
	console.log(this);
}

let school = {
	name: '尚硅谷',
	getName(){
		let fn5 = () => {
			console.log(this);
		}
		fn5();
	}
};
```

注意：箭头函数不会更改 this 指向，用来指定回调函数会非常合适。

### 1.7 参数默认值

```js
//ES6 允许给函数参数赋值初始值
//形参初始值 具有默认值的参数, 一般位置要靠后(潜规则)
function add(a, b, c = 10) {
	return a + b + c;
}
let result = add(1, 2);
console.log(result);

//与解构赋值结合
function connect({host="127.0.0.1", username, password, port}){
	console.log(host)
	console.log(username)
	console.log(password)
	console.log(port)
}
connect({
	host: 'atguigu.com',
	username: 'root',
	password: 'root',
	port: 3306
})
```

### 1.8 rest 参数

ES 6 引入 rest 参数，用于获取函数的实参，用来代替 arguments。

```js
/**
* 作用与 arguments 类似
*/
function add(...args){
	console.log(args);
}
add(1, 2, 3, 4, 5);

/**
* rest 参数必须是最后一个形参
*/
function minus(a, b, ...args){
	console.log(a, b, args);
}
minus(100, 1, 2, 3, 4, 5, 19);
```

注意：rest 参数非常适合不定个数参数函数的场景。

### 1.9 spread 扩展运算符

扩展运算符（spread）也是三个点（...）。它好比 rest 参数的逆运算，将一个数组转为用逗号分隔的参数序列，对数组进行解包。

```js
// 『...』 扩展运算符能将『数组』转换为逗号分隔的『参数序列』
//声明一个数组 ...
const tfboys = ['易烊千玺','王源','王俊凯'];
// => '易烊千玺','王源','王俊凯'

// 声明一个函数
function chunwan(){
	console.log(arguments);
}

chunwan(...tfboys);// chunwan('易烊千玺','王源','王俊凯')

```

拓展运算符的应用：

```js
//1. 数组的合并 情圣  误杀  唐探
const kuaizi = ['王太利', '肖央'];
const fenghuang = ['曾毅', '玲花'];
const zuixuanxiaopingguo = [...kuaizi, ...fenghuang];
console.log(zuixuanxiaopingguo);

//2. 数组的克隆
const sanzhihua = ['E','G','M'];
const sanyecao = [...sanzhihua];//  ['E','G','M']
console.log(sanyecao);

//3. 将伪数组转为真正的数组
const divs = document.querySelectorAll('div');
const divArr = [...divs];
console.log(divArr);// arguments

/**
* 4. 展开对象
*/
let skillOne = {
	q: '致命打击',
};
let skillTwo = {
	w: '勇气'
};
let skillThree = {
	e: '审判'
};
let skillFour = {
	r: '德玛西亚正义'
};
let gailun = {...skillOne, ...skillTwo, ...skillThree, ...skillFour};
```

### 1.10 Symbol

#### 1.10.1 Symbol 的基本使用

ES 6 引入了一种新的原始数据类型 Symbol，表示独一无二的值。它是 JavaScript 语言的第七种数据类型，是一种类似于字符串的数据类型。

Symbol 特点：

1.  Symbol 的值是唯一的，用来解决命名冲突的问题；
2.  Symbol 值不能与其他数据进行运算；
3.  Symbol 定 义 的 对 象 属 性 不 能 使 用 `for...in` 循 环 遍 历 ， 但 是 可 以 使 用 `Reflect.ownKeys` 来获取对象的所有键名。

```js
//创建 Symbol
let s1 = Symbol();
console.log(s1, typeof s1);

//添加标识的 Symbol
let s2 = Symbol("胡宇婷");
let s3 = Symbol("胡宇婷");

console.log(s2 === s3);

//使用 Symbol for 定义
let s4 = Symbol.for('胡宇婷');
console.log(s4, typeof s4);

let s5 = Symbol.for('胡宇婷');
console.log(s4 === s5);

// USONB  you are so niubility
// u  undefined
// s  string  symbol
// o  object
// n  null number
// b  boolean
```

注: 遇到唯一性的场景时要想到 Symbol。

#### 1.10.2 Symbol 创建对象属性

```js
//向对象中添加方法 up down
let game = {
	name: '俄罗斯方块',
	up: function () { },
	down: function () { }
};
//声明一个对象
let methods = {
	up: Symbol(),
	down: Symbol()
};
game[methods.up] = function () {
	console.log("我可以改变形状");
}
game[methods.down] = function () {
	console.log("我可以快速下降!!");
}
console.log(game);

// 第二种方式
let youxi = {
	name: "狼人杀",
	[Symbol('say')]: function () {
		console.log("我可以发言")
	},
	[Symbol('zibao')]: function () {
		console.log('我可以自爆');
	}
}

console.log(youxi)
```

#### 1.10.3 Symbol 内置值

除了定义自己使用的 Symbol 值以外，ES 6 还提供了 11 个内置的 Symbol 值，指向语言内部使用的方法。可以称这些方法为魔术方法，因为它们会在特定的场景下自动执行。

|             值              |                                                        说明                                                         |
| :-------------------------: | :-----------------------------------------------------------------------------------------------------------------: |
|    `Symbol.hasInstance`     |                    当其他对象使用 instanceof 运算符，判断是否为该对象的实例时，会调用这个方法。                     |
| `Symbol.isConcatSpreadable` | 对象的 `Symbol.isConcatSpreadable` 属性等于的是一个布尔值，表示该对象用于 `Array.prototype.concat()` 是否可以展开。 |
|      `Symbol.species`       |                                           创建衍生对象时，会使用该属性。                                            |
|       `Symbol.match`        |                   当执行 `str.match(myObject)` 时，如果该属性存在，会调用它，返回该方法的返回值。                   |
|      `Symbol.replace`       |                        当该对象被 `str.replace(myObject)` 方法调用时，会返回该方法的返回值。                        |
|       `Symbol.search`       |                        当该对象被 `str.search(myObject)` 方法调用时，会返回该方法的返回值。                         |
|       `Symbol.split`        |                         当该对象被 `str.split(myObject)` 方法调用时，会返回该方法的返回值。                         |
|      `Symbol.iterator`      |                 对象进行 `for...of` 循环时，会调用 `Symbol.iterator` 方法，返回该对象的默认遍历器。                 |
|    `Symbol.toPrimitive`     |                      该对象被转为原始类型的值时，会调用这个方法，返回该对象对应的原始类型值。                       |
|    `Symbol.toStringTag`     |                               在该对象上面调用 `toString` 方法时，返回该方法的返回值                                |
|    `Symbol.unscopables`     |                          该对象指定了使用 `with` 关键字时，哪些属性会被 `with` 环境排除。                           |

```js
class Person {
	static [Symbol.hasInstance](param) {
		console.log(param);
		console.log("我被用来检测类型了");
		return false;
	}
}

let o = {};

console.log(o instanceof Person);

const arr = [1,2,3];
const arr2 = [4,5,6];
arr2[Symbol.isConcatSpreadable] = false;
console.log(arr.concat(arr2));
```

### 1.11 迭代器

遍历器（Iterator）就是一种机制。它是一种接口，为各种不同的数据结构提供统一的访问机制。任何数据结构只要部署 Iterator 接口，就可以完成遍历操作。

1.  ES 6 创造了一种新的遍历命令 `for...of` 循环，Iterator 接口主要供 `for...of` 消费。
2.  原生具备 Iterator 接口的数据（可用 `for...of` 遍历）:
    1.  Array
    2.  Arguments
    3.  Set
    4.  Map
    5.  String
    6.  TypedArray
    7.  NodeList
3.  工作原理：
    1.  创建一个指针对象，指向当前数据结构的起始位置；
    2.  第一次调用对象的 next 方法，指针自动指向数据结构的第一个成员；
    3.  接下来不断调用 next 方法，指针一直往后移动，直到指向最后一个成员；
    4.  每调用 next 方法返回一个包含 value 和 done 属性的对象。

注: 需要自定义遍历数据的时候，要想到迭代器。

```js
//声明一个数组
const xiyou = ['唐僧','孙悟空','猪八戒','沙僧'];

//使用 for...of 遍历数组
for(let v of xiyou){
	console.log(v);
}

let iterator = xiyou[Symbol.iterator]();

//调用对象的next方法
// console.log(iterator.next());
// console.log(iterator.next());
// console.log(iterator.next());
// console.log(iterator.next());
// console.log(iterator.next());

while (true) {
	const cur = iterator.next();
	console.log(cur.value);
	if (cur.done) {
		break;
	}
}
```

案例：

```js
//声明一个对象
const banji = {
	name: "终极一班",
	stus: [
		'xiaoming',
		'xiaoning',
		'xiaotian',
		'knight'
	],
	[Symbol.iterator]() {
		//索引变量
		let index = 0;
		//
		let _this = this;
		return {
			next: function () {
				if (index < _this.stus.length) {
					const result = { value: _this.stus[index], done: false };
					//下标自增
					index++;
					//返回结果
					return result;
				} else {
					return { value: undefined, done: true };
				}
			}
		};
	}
}

//遍历这个对象
for (let v of banji) {
	console.log(v);
}
```

### 1.12 生成器

#### 1.12.1 生成器介绍

生成器函数是 ES 6 提供的一种异步编程解决方案，语法行为与传统函数完全不同。

```js
//生成器其实就是一个特殊的函数
//异步编程  纯回调函数  node fs  ajax mongodb
//函数代码的分隔符
function * gen() {
	// console.log(111);
	yield '一只没有耳朵';
	// console.log(222);
	yield '一只没有尾部';
	// console.log(333);
	yield '真奇怪';
	// console.log(444);
}

let iterator = gen();
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());

//遍历
// for(let v of gen()){
//     console.log(v);
// }
```

代码说明：

1.  -   的位置没有限制；
2.  生成器函数返回的结果是迭代器对象，调用迭代器对象的 next 方法可以得到 yield 语句后的值；
3.  yield 相当于函数的暂停标记，也可以认为是函数的分隔符，每调用一次 next 方法，执行一段代码；
4.  next 方法可以传递实参，作为 yield 语句的返回值。

#### 1.12.2 生成器函数参数传递

```js
 function * gen(arg){
	console.log(arg);
	let one = yield 111;
	console.log(one);
	let two = yield 222;
	console.log(two);
	let three = yield 333;
	console.log(three);
}

//执行获取迭代器对象
let iterator = gen('AAA');
console.log(iterator.next());
//next方法可以传入实参
console.log(iterator.next('BBB'));
console.log(iterator.next('CCC'));
console.log(iterator.next('DDD'));
```

#### 1.12.3 案例

##### 案例一

```js
// 异步编程  文件操作 网络操作(ajax, request) 数据库操作
// 1s 后控制台输出 111  2s后输出 222  3s后输出 333
// 回调地狱
setTimeout(() => {
	console.log(111);
	setTimeout(() => {
		console.log(222);
		setTimeout(() => {
			console.log(333);
		}, 3000);
	}, 2000);
}, 1000);

function one() {
	setTimeout(() => {
		console.log(111);
		iterator.next();
	}, 1000)
}

function two() {
	setTimeout(() => {
		console.log(222);
		iterator.next();
	}, 2000)
}

function three() {
	setTimeout(() => {
		console.log(333);
		iterator.next();
	}, 3000)
}

function* gen() {
	yield one();
	yield two();
	yield three();
}

//调用生成器函数
let iterator = gen();
iterator.next();
```

##### 案例二

```js
//模拟获取  用户数据  订单数据  商品数据
function getUsers() {
	setTimeout(() => {
		let data = '用户数据';
		//调用 next 方法, 并且将数据传入
		iterator.next(data);
	}, 1000);
}

function getOrders() {
	setTimeout(() => {
		let data = '订单数据';
		iterator.next(data);
	}, 1000)
}

function getGoods() {
	setTimeout(() => {
		let data = '商品数据';
		iterator.next(data);
	}, 1000)
}

function* gen() {
	let users = yield getUsers();
	let orders = yield getOrders();
	let goods = yield getGoods();
}

//调用生成器函数
let iterator = gen();
iterator.next();
```

### 1.13 Promise

Promise 是 ES 6 引入的异步编程的新解决方案。语法上 Promise 是一个构造函数，用来封装异步操作并可以获取其成功或失败的结果。

1.  Promise 构造函数: Promise(excutor) {}
2.  Promise.prototype.then 方法
3.  Promise.prototype.catch 方法

#### 1.13.1 Promise 基本语法

```js
//实例化 Promise 对象
const p = new Promise(function (resolve, reject) {
	setTimeout(function () {
		//
		// let data = '数据库中的用户数据';
		// resolve
		// resolve(data);

		let err = '数据读取失败';
		reject(err);
	}, 1000);
});

//调用 promise 对象的 then 方法
p.then(function (value) {
	console.log(value);
}, function (reason) {
	console.error(reason);
})
```

#### 1.13.2 Promise 封装读取文件

```js
//1. 引入 fs 模块
const fs = require('fs');

//2. 调用方法读取文件
// fs.readFile('./resources/为学.md', (err, data)=>{
//     //如果失败, 则抛出错误
//     if(err) throw err;
//     //如果没有出错, 则输出内容
//     console.log(data.toString());
// });

//3. 使用 Promise 封装
const p = new Promise(function (resolve, reject) {
    fs.readFile("./resources/为学.md", (err, data) => {
        //判断如果失败
        if (err) reject(err);
        //如果成功
        resolve(data);
    });
});

p.then(function (value) {
    console.log(value.toString());
}, function (reason) {
    console.log("读取失败!!");
});
```

#### 1.13.3 Promise 封装 AJAX

```js
// 接口地址: https://api.apiopen.top/getJoke
const p = new Promise((resolve, reject) => {
	//1. 创建对象
	const xhr = new XMLHttpRequest();

	//2. 初始化
	xhr.open("GET", "https://api.apiopen.top/getJ");

	//3. 发送
	xhr.send();

	//4. 绑定事件, 处理响应结果
	xhr.onreadystatechange = function () {
		//判断
		if (xhr.readyState === 4) {
			//判断响应状态码 200-299
			if (xhr.status >= 200 && xhr.status < 300) {
				//表示成功
				resolve(xhr.response);
			} else {
				//如果失败
				reject(xhr.status);
			}
		}
	}
})

//指定回调
p.then(function (value) {
	console.log(value);
}, function (reason) {
	console.error(reason);
});
```

#### 1.13.4 Promise then 方法

```js
//创建 promise 对象
const p = new Promise((resolve, reject) => {
	setTimeout(() => {
		resolve('用户数据');
		// reject('出错啦');
	}, 1000)
});

//调用 then 方法  then方法的返回结果是 Promise 对象, 对象状态由回调函数的执行结果决定
//1. 如果回调函数中返回的结果是 非 promise 类型的属性, 状态为成功, 返回值为对象的成功的值

const result = p.then(value => {
	console.log(value);
	//1. 非 promise 类型的属性
	//return 'iloveyou';
	//2. 是 promise 对象
	return new Promise((resolve, reject) => {
		// resolve('ok');
		reject('error');
	});
	//3. 抛出错误
	// throw new Error('出错啦!');
	// throw '出错啦!';
}, reason => {
	console.warn(reason);
});

//链式调用
p.then(value => {

}).then(value => {

});
```

#### 1.13.5 Promise 读取多个文件

```js
//引入 fs 模块
const fs = require("fs");

// fs.readFile('./resources/为学.md', (err, data1)=>{
//     fs.readFile('./resources/插秧诗.md', (err, data2)=>{
//         fs.readFile('./resources/观书有感.md', (err, data3)=>{
//             let result = data1 + '\r\n' +data2  +'\r\n'+ data3;
//             console.log(result);
//         });
//     });
// });

//使用 promise 实现
const p = new Promise((resolve, reject) => {
    fs.readFile("./resources/为学.md", (err, data) => {
        resolve(data);
    });
});

p.then(value => {
    return new Promise((resolve, reject) => {
        fs.readFile("./resources/插秧诗.md", (err, data) => {
            resolve([value, data]);
        });
    });
}).then(value => {
    return new Promise((resolve, reject) => {
        fs.readFile("./resources/观书有感.md", (err, data) => {
            //压入
            value.push(data);
            resolve(value);
        });
    })
}).then(value => {
    console.log(value.join('\r\n'));
});
```

#### 1.13.6 Promise catch 方法

```js
const p = new Promise((resolve, reject) => {
	setTimeout(() => {
		//设置 p 对象的状态为失败, 并设置失败的值
		reject("出错啦!");
	}, 1000)
});

// p.then(function(value){}, function(reason){
//     console.error(reason);
// });

p.catch(function (reason) {
	console.warn(reason);
});
```

### 1.14 Set

ES 6 提供了新的数据结构 Set（集合）。它类似于数组，但成员的值都是唯一的，集合实现了 iterator 接口，所以可以使用「扩展运算符」和「for...of...」进行遍历，集合的属性和方法：

1.  size：返回集合的元素个数。
2.  add：增加一个新元素，返回当前集合；
3.  delete：删除元素，返回 boolean 值；
4.  has：检测集合中是否包含某个元素，返回 boolean 值；
5.  clear：清空集合，返回 undefined.

```js
//声明一个 set
let s = new Set();
let s2 = new Set(['大事儿', '小事儿', '好事儿', '坏事儿', '小事儿']);

//元素个数
console.log(s2.size);
//添加新的元素
s2.add('喜事儿');
//删除元素
s2.delete('坏事儿');
//检测
console.log(s2.has('糟心事'));
//清空
s2.clear();
console.log(s2);

for (let v of s2) {
	console.log(v);
}

let arr = [1, 2, 3, 4, 5, 4, 3, 2, 1];
//1. 数组去重
let result = [...new Set(arr)];
console.log(result);

//2. 交集
let arr2 = [4, 5, 6, 5, 6];
result = [...new Set(arr)].filter(item => {
	let s2 = new Set(arr2);// 4 5 6
	if (s2.has(item)) {
		return true;
	} else {
		return false;
	}
});

// let result = [...new Set(arr)].filter(item => new Set(arr2).has(item));
// console.log(result);

//3. 并集
let union = [...new Set([...arr, ...arr2])];
console.log(union);

//4. 差集
let diff = [...new Set(arr)].filter(item => !(new Set(arr2).has(item)));
console.log(diff);
```

### 1.15 Map

ES6 提供了 Map 数据结构。它类似于对象，也是键值对的集合。但是「键」的范围不限于字符串，各种类型的值（包括对象）都可以当作键。Map 也实现了 iterator 接口，所以可以使用「扩展运算符」和「for...of...」进行遍历。Map 的属
性和方法：

1.  size：返回 Map 的元素个数。
2.  set：增加一个新元素，返回当前 Map.
3.  get：返回键名对象的键值。
4.  has：检测 Map 中是否包含某个元素，返回 boolean 值.
5.  clear：清空集合，返回 undefined.

```js
//声明 Map
let m = new Map();

//添加元素
m.set('name', '尚硅谷');
m.set('change', function () {
	console.log("我们可以改变你!!");
});
let key = {
	school: 'ATGUIGU'
};
m.set(key, ['北京', '上海', '深圳']);

size
console.log(m.size);

删除
m.delete('name');

获取
console.log(m.get('change'));
console.log(m.get(key));

清空
m.clear();

//遍历
for (let v of m) {
	console.log(v);
}
```

### 1.16 class

ES 6 提供了更接近传统语言的写法，引入了 class（类）这个概念，作为对象的模板。通过 class 关键字，可以定义类。基本上，ES 6 的 class 可以看作只是一个语法糖，它的绝大部分功能，ES 5 都可以做到，新的 class 写法只是让对象原型的写法更加清晰、更像面向对象编程的语法而已。
知识点：

1.  class 声明类；
2.  constructor 定义构造函数初始化；
3.  extends 继承父类；
4.  super 调用父级构造方法；
5.  static 定义静态方法和属性；
6.  父类方法可以重写。

```js
//手机
function Phone(brand, price) {
	this.brand = brand;
	this.price = price;
}

//添加方法
Phone.prototype.call = function () {
	console.log("我可以打电话!!");
}

//实例化对象
let Huawei = new Phone('华为', 5999);
Huawei.call();
console.log(Huawei);

//class
class Shouji {
	//构造方法 名字不能修改
	constructor(brand, price) {
		this.brand = brand;
		this.price = price;
	}

	//方法必须使用该语法, 不能使用 ES5 的对象完整形式
	call() {
		console.log("我可以打电话!!");
	}
}

let onePlus = new Shouji("1+", 1999);

console.log(onePlus);
```

#### 1.16.1 类的静态成员

```js
// function Phone(){

// }
// Phone.name = '手机';
// Phone.change = function(){
//     console.log("我可以改变世界");
// }
// Phone.prototype.size = '5.5inch';

// let nokia = new Phone();

// console.log(nokia.name);
// // nokia.change();
// console.log(nokia.size);

class Phone {
	//静态属性
	static name = '手机';
	static change() {
		console.log("我可以改变世界");
	}
}

let nokia = new Phone();
console.log(nokia.name);
console.log(Phone.name);
```

#### 1.16.2 继承

使用 ES 5 的继承：

```js
//手机
function Phone(brand, price) {
	this.brand = brand;
	this.price = price;
}

Phone.prototype.call = function () {
	console.log("我可以打电话");
}

//智能手机
function SmartPhone(brand, price, color, size) {
	Phone.call(this, brand, price);
	this.color = color;
	this.size = size;
}

//设置子级构造函数的原型
SmartPhone.prototype = new Phone;
SmartPhone.prototype.constructor = SmartPhone;

//声明子类的方法
SmartPhone.prototype.photo = function () {
	console.log("我可以拍照")
}

SmartPhone.prototype.playGame = function () {
	console.log("我可以玩游戏");
}

const chuizi = new SmartPhone('锤子', 2499, '黑色', '5.5inch');

console.log(chuizi);
```

使用 ES 6 的继承：

```js
class Phone {
	//构造方法
	constructor(brand, price) {
		this.brand = brand;
		this.price = price;
	}
	//父类的成员属性
	call() {
		console.log("我可以打电话!!");
	}
}

class SmartPhone extends Phone {
	//构造方法
	constructor(brand, price, color, size) {
		super(brand, price);// Phone.call(this, brand, price)
		this.color = color;
		this.size = size;
	}

	photo() {
		console.log("拍照");
	}

	playGame() {
		console.log("玩游戏");
	}

	call() {
		console.log('我可以进行视频通话');
	}
}

const xiaomi = new SmartPhone('小米', 799, '黑色', '4.7inch');
// console.log(xiaomi);
xiaomi.call();
xiaomi.photo();
xiaomi.playGame();
```

#### 1.16.3 get 和 set

```js
// get 和 set
class Phone {
	get price() {
		console.log("价格属性被读取了");
		return 'iloveyou';
	}

	set price(newVal) {
		console.log('价格属性被修改了');
	}
}

//实例化对象
let s = new Phone();

// console.log(s.price);
s.price = 'free';
```

### 1.17 数值扩展

```js
//0. Number.EPSILON 是 JavaScript 表示的最小精度
//EPSILON 属性的值接近于 2.2204460492503130808472633361816E-16
function equal(a, b) {
	if (Math.abs(a - b) < Number.EPSILON) {
		return true;
	} else {
		return false;
	}
}
console.log(0.1 + 0.2 === 0.3);
console.log(equal(0.1 + 0.2, 0.3))

//1. 二进制和八进制
let b = 0b1010;
let o = 0o777;
let d = 100;
let x = 0xff;
console.log(x);

//2. Number.isFinite  检测一个数值是否为有限数
console.log(Number.isFinite(100));
console.log(Number.isFinite(100 / 0));
console.log(Number.isFinite(Infinity));

//3. Number.isNaN 检测一个数值是否为 NaN
console.log(Number.isNaN(123));

//4. Number.parseInt Number.parseFloat字符串转整数
console.log(Number.parseInt('5211314love'));
console.log(Number.parseFloat('3.1415926神奇'));

//5. Number.isInteger 判断一个数是否为整数
console.log(Number.isInteger(5));
console.log(Number.isInteger(2.5));

//6. Math.trunc 将数字的小数部分抹掉
console.log(Math.trunc(3.5));

//7. Math.sign 判断一个数到底为正数 负数 还是零
console.log(Math.sign(100));
console.log(Math.sign(0));
console.log(Math.sign(-20000));
```

### 1.18 对象扩展

![](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/20221207122826.png)

ES 6 新增了一些 Object 对象的方法：

1.  `Object.is` 比较两个值是否严格相等，与「===」行为基本一致（+0 与 NaN）。
2.  Object.assign 对象的合并，将源对象的所有可枚举属性，复制到目标对象。
3.  `__proto__`、`setPrototypeOf`、`setPrototypeOf` 可以直接设置对象的原型。

```js
// 1. Object.is 判断两个值是否完全相等
console.log(Object.is(120, 120));// ===
console.log(Object.is(NaN, NaN));// ===
console.log(NaN === NaN);// ===

// 2. Object.assign 对象的合并
const config1 = {
	host: 'localhost',
	port: 3306,
	name: 'root',
	pass: 'root',
	test: 'test'
};
const config2 = {
	host: 'http://atguigu.com',
	port: 33060,
	name: 'atguigu.com',
	pass: 'iloveyou',
	test2: 'test2'
}
console.log(Object.assign(config1, config2));

// 3. Object.setPrototypeOf 设置原型对象  Object.getPrototypeof
const school = {
	name: '尚硅谷'
}
const cities = {
	xiaoqu: ['北京', '上海', '深圳']
}
Object.setPrototypeOf(school, cities);
console.log(Object.getPrototypeOf(school));
console.log(school);
```

### 1.19 模块化

模块化是指将一个大的程序文件，拆分成许多小的文件，然后将小文件组合起来。

模块化的好处：

1.  止命名冲突；
2.  代码复用；
3.  高维护性。

ES 6 之前的模块化规范有：

1.  CommonJS => NodeJS、Browserify
2.  AMD => requireJS
3.  CMD => seaJS

ES6 模块化语法：
模块功能主要由两个命令构成：export 和 import：

-   export 命令用于规定模块的对外接口；
-   import 命令用于输入其他模块提供的功能。

#### 1.19.1 模块暴露语法

##### 分别暴露

```js
//分别暴露
export let school = '尚硅谷';

export function teach() {
    console.log("我们可以教给你开发技能");
}
```

##### 统一暴露

```js
//统一暴露
let school = '尚硅谷';

function findJob() {
    console.log("我们可以帮助你找工作!!");
}

export {school, findJob};
```

##### 默认暴露

```js
//默认暴露
export default {
    school: 'ATGUIGU',
    change: function() {
        console.log("我们可以改变你!!");
    }
}
```

#### 1.19.2 模块导入语法

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ES6 模块化</title>
</head>
<body>
    <script type="module">
        //1. 通用的导入方式
        //引入 m1.js 模块内容
        // import * as m1 from "./src/js/m1.js";
        // //引入 m2.js 模块内容
        // import * as m2 from "./src/js/m2.js";
        // //引入 m3.js
        // import * as m3 from "./src/js/m3.js";

        //2. 解构赋值形式
        // import {school, teach} from "./src/js/m1.js";
        // import {school as guigu, findJob} from "./src/js/m2.js";
        // import {default as m3} from "./src/js/m3.js";

        //3. 简便形式  针对默认暴露
        // import m3 from "./src/js/m3.js";
        // console.log(m3);
    </script>

    <script src="./src/js/app.js" type="module"></script>
</body>
</html>
```

#### 1.19.3 babel

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <!--
        1. 安装工具 npm i babel-cli babel-preset-env browserify(webpack) -D
        2. 编译 npx babel src/js -d dist/js --presets=babel-preset-env
        3. 打包 npx browserify dist/js/app.js -o dist/bundle.js
     -->
    <script src="dist/bundle.js"></script>
</body>

</html>
```

## 二、ES 7 新特性

-   `Array.prototype.includes`：Includes 方法用来检测数组中是否包含某个元素，返回布尔类型值。
-   指数操作符：在 ES 7 中引入指数运算符`**`，用来实现幂运算，功能与 `Math.pow()` 结果相同。

## 三、ES 8 新特性

### 3.1 async 和 await

async 和 await 两种语法结合可以让异步代码像同步代码一样。

#### 3.1.1 async 函数

1.  async 函数的返回值为 promise 对象。
2.  promise 对象的结果由 async 函数执行的返回值决定。

```js
//async 函数
async function fn() {
	// 返回一个字符串
	// return '尚硅谷';
	// 返回的结果不是一个 Promise 类型的对象, 返回的结果就是成功 Promise 对象
	// return;
	//抛出错误, 返回的结果是一个失败的 Promise
	// throw new Error('出错啦!');
	//返回的结果如果是一个 Promise 对象
	return new Promise((resolve, reject) => {
		resolve('成功的数据');
		// reject("失败的错误");
	});
}

const result = fn();

//调用 then 方法
result.then(value => {
	console.log(value);
}, reason => {
	console.warn(reason);
})
```

#### 3.1.2 await 函数

1.  await 必须写在 async 函数中；
2.  await 右侧的表达式一般为 promise 对象；
3.  await 返回的是 promise 成功的值；
4.  await 的 promise 失败了, 就会抛出异常, 需要通过 try...catch 捕获处理。

```js
//创建 promise 对象
const p = new Promise((resolve, reject) => {
	// resolve("用户数据");
	reject("失败啦!");
})

// await 要放在 async 函数中.
async function main() {
	try {
		let result = await p;
		//
		console.log(result);
	} catch (e) {
		console.log(e);
	}
}
//调用函数
main();
```

#### 3.1.3 async 和 await 结合读取文件

```js
//1. 引入 fs 模块
const fs = require("fs");

//读取『为学』
function readWeiXue() {
    return new Promise((resolve, reject) => {
        fs.readFile("./resources/为学.md", (err, data) => {
            //如果失败
            if (err) reject(err);
            //如果成功
            resolve(data);
        })
    })
}

function readChaYangShi() {
    return new Promise((resolve, reject) => {
        fs.readFile("./resources/插秧诗.md", (err, data) => {
            //如果失败
            if (err) reject(err);
            //如果成功
            resolve(data);
        })
    })
}

function readGuanShu() {
    return new Promise((resolve, reject) => {
        fs.readFile("./resources/观书有感.md", (err, data) => {
            //如果失败
            if (err) reject(err);
            //如果成功
            resolve(data);
        })
    })
}

//声明一个 async 函数
async function main(){
    //获取为学内容
    let weixue = await readWeiXue();
    //获取插秧诗内容
    let chayang = await readChaYangShi();
    // 获取观书有感
    let guanshu = await readGuanShu();

    console.log(weixue.toString());
    console.log(chayang.toString());
    console.log(guanshu.toString());
}

main();
```

#### 3.1.4 async 与 await 封装 AJAX 请求

```js
// 发送 AJAX 请求, 返回的结果是 Promise 对象
function sendAJAX(url) {
	return new Promise((resolve, reject) => {
		//1. 创建对象
		const x = new XMLHttpRequest();

		//2. 初始化
		x.open('GET', url);

		//3. 发送
		x.send();

		//4. 事件绑定
		x.onreadystatechange = function () {
			if (x.readyState === 4) {
				if (x.status >= 200 && x.status < 300) {
					//成功啦
					resolve(x.response);
				} else {
					//如果失败
					reject(x.status);
				}
			}
		}
	})
}

//promise then 方法测试
// sendAJAX("https://api.apiopen.top/getJoke").then(value=>{
//     console.log(value);
// }, reason=>{})

// async 与 await 测试  axios
async function main() {
	//发送 AJAX 请求
	let result = await sendAJAX("https://api.apiopen.top/getJoke");
	//再次测试
	let tianqi = await sendAJAX('https://www.tianqiapi.com/api/version=v1&city=%E5%8C%97%E4%BA%AC&appid=23941491&appsecret=TXoD5e8P')

	console.log(tianqi);
}

main();
```

### 3.2 对象方法扩展

1.  `Object.keys()`：方法返回一个给定对象的所有可枚举属性键的数组。
2.  `Object.values()`：方法返回一个给定对象的所有可枚举属性值的数组。
3.  `Object.entries()`：方法返回一个给定对象自身可遍历属性 `[key, value]` 的数组。
4.  `Object.getOwnPropertyDescriptors`：该方法返回指定对象所有自身属性的描述对象

```js
//声明对象
const school = {
	name: "尚硅谷",
	cities: ['北京', '上海', '深圳'],
	xueke: ['前端', 'Java', '大数据', '运维']
};

// 获取对象所有的键
console.log(Object.keys(school));
// 获取对象所有的值
console.log(Object.values(school));
entries
console.log(Object.entries(school));
// 创建 Map
const m = new Map(Object.entries(school));
console.log(m.get('cities'));

// 对象属性的描述对象
console.log(Object.getOwnPropertyDescriptors(school));

const obj = Object.create(null, {
	name: {
		//设置值
		value: '尚硅谷',
		//属性特性
		writable: true,
		configurable: true,
		enumerable: true
	}
});
```

## 四、ES 9 新特性

### 4.1 对象展开

rest 参数与 spread 扩展运算符在 ES 6 中已经引入，不过 ES 6 中只针对于数组，在 ES 9 中为对象提供了像数组一样的 rest 参数和扩展运算符。

```js
//rest 参数
function connect({host, port, ...user}){
	console.log(host);
	console.log(port);
	console.log(user);
}

connect({
	host: '127.0.0.1',
	port: 3306,
	username: 'root',
	password: 'root',
	type: 'master'
});


//对象合并
const skillOne = {
	q: '天音波'
}

const skillTwo = {
	w: '金钟罩'
}

const skillThree = {
	e: '天雷破'
}
const skillFour = {
	r: '猛龙摆尾'
}

const mangseng = {...skillOne, ...skillTwo, ...skillThree, ...skillFour};

console.log(mangseng)

// ...skillOne   =>  q: '天音波', w: '金钟罩'
```

### 4.2 正则拓展

#### 4.2.1 正则表达式命名捕获组

ES 9 允许命名捕获组使用符号 `?<name>`，这样获取捕获结果可读性更强。

```js
let str = '<a href="http://www.atguigu.com">尚硅谷</a>';
const reg = /<a href="(?<url>.*)">(?<text>.*)<\/a>/;
const result = reg.exec(str);
console.log(result.groups.url);
console.log(result.groups.text);
```

#### 4.2.2 正则表达式反向断言

ES 9 支持反向断言，通过对匹配结果前面的内容进行判断，对匹配进行筛选。

```js
//声明字符串
let str = 'JS5211314 你知道么 555 啦啦啦';
//正向断言
const reg = /\d+(?=啦)/;
const result = reg.exec(str);
//反向断言
const reg = /(?<=么)\d+/;
const result = reg.exec(str);
console.log(result);
```

#### 4.2.3 正则表达式 dotAll 模式

正则表达式中点.匹配除回车外的任何单字符，标记『s』改变这种行为，允许行终止符出现。

```JS
 //dot  .  元字符  除换行符以外的任意单个字符
let str = `
<ul>
	<li>
		<a>肖生克的救赎</a>
		<p>上映日期: 1994-09-10</p>
	</li>
	<li>
		<a>阿甘正传</a>
		<p>上映日期: 1994-07-06</p>
	</li>
</ul>`;
//声明正则
// const reg = /<li>\s+<a>(.*?)<\/a>\s+<p>(.*?)<\/p>/;
const reg = /<li>.*?<a>(.*?)<\/a>.*?<p>(.*?)<\/p>/gs;
//执行匹配
// const result = reg.exec(str);
let result;
let data = [];
while(result = reg.exec(str)){
	data.push({title: result[1], time: result[2]});
}
	//输出结果
console.log(data);
```

## 五、ES 10 新特性

### 5.1 Object.fromEntries 和 Object.entries

```js
//二维数组
// const result = Object.fromEntries([
//     ['name','尚硅谷'],
//     ['xueke', 'Java,大数据,前端,云计算']
// ]);

//Map
// const m = new Map();
// m.set('name','ATGUIGU');
// const result = Object.fromEntries(m);

//Object.entries ES8
const arr = Object.entries({
	name: "尚硅谷"
})
console.log(arr);
```

### 5.2 trimStart 和 trimEnd

```js
// trim
let str = '   iloveyou   ';

console.log(str);
console.log(str.trimStart());
console.log(str.trimEnd());
```

### 5.3 Array.prototype.flat 与 flatMap

```js
//flat 平
//将多维数组转化为低位数组
// const arr = [1,2,3,4,[5,6]];
// const arr = [1,2,3,4,[5,6,[7,8,9]]];
//参数为深度 是一个数字
// console.log(arr.flat(2));

//flatMap
const arr = [1, 2, 3, 4];
const result = arr.flatMap(item => [item * 10]);
console.log(result);
```

### 5.4 Symbol.prototype.description

```js
//创建 Symbol
let s = Symbol('尚硅谷');

console.log(s.description);
```

## 六、ES 11 新特性

### 6.1 类的私有属性

```js
class Person {
	//公有属性
	name;
	//私有属性
	#age;
	#weight;
	//构造方法
	constructor(name, age, weight) {
		this.name = name;
		this.#age = age;
		this.#weight = weight;
	}

	intro() {
		console.log(this.name);
		console.log(this.#age);
		console.log(this.#weight);
	}
}

//实例化
const girl = new Person('晓红', 18, '45kg');

// console.log(girl.name);
// console.log(girl.#age);
// console.log(girl.#weight);

girl.intro();
```

### 6.2 Promise.allSettled

```js
//声明两个promise对象
const p1 = new Promise((resolve, reject) => {
	setTimeout(() => {
		resolve('商品数据 - 1');
	}, 1000)
});

const p2 = new Promise((resolve, reject) => {
	setTimeout(() => {
		resolve('商品数据 - 2');
		// reject('出错啦!');
	}, 1000)
});

//调用 allsettled 方法
const result = Promise.allSettled([p1, p2]);

const res = Promise.all([p1, p2]);

console.log(res);
```

### 6.3 String.prototype.matchAll

```js
let str = `<ul>
	<li>
		<a>肖生克的救赎</a>
		<p>上映日期: 1994-09-10</p>
	</li>
	<li>
		<a>阿甘正传</a>
		<p>上映日期: 1994-07-06</p>
	</li>
</ul>`;

//声明正则
const reg = /<li>.*?<a>(.*?)<\/a>.*?<p>(.*?)<\/p>/sg

//调用方法
const result = str.matchAll(reg);

// for(let v of result){
//     console.log(v);
// }

const arr = [...result];

console.log(arr);
```

### 6.4 可选链操作符

```js
// ?.
function main(config) {
	// const dbHost = config && config.db && config.db.host;
	const dbHost = config?.db?.host;

	console.log(dbHost);
}

main({
	db: {
		host: '192.168.1.100',
		username: 'root'
	},
	cache: {
		host: '192.168.1.200',
		username: 'admin'
	}
})
```

### 6.5 动态 import

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>动态 import </title>
</head>
<body>
    <button id="btn">点击</button>
    <script src="./js/app.js" type="module"></script>
</body>
</html>
```

```js
// import * as m1 from "./hello.js";
//获取元素
const btn = document.getElementById('btn');

btn.onclick = function () {
    import('./hello.js').then(module => {
        module.hello();
    });
}
```

```js
export function hello(){
    alert('Hello');
}
```

### 6.6 BigInt

```js
 //大整形
// let n = 521n;
// console.log(n, typeof(n));

//函数
// let n = 123;
// console.log(BigInt(n));
// console.log(BigInt(1.2));

//大数值运算
let max = Number.MAX_SAFE_INTEGER;
console.log(max);
console.log(max + 1);
console.log(max + 2);

console.log(BigInt(max))
console.log(BigInt(max) + BigInt(1))
console.log(BigInt(max) + BigInt(2))
```

### 6.7 globalThis 对象

```js
console.log(globalThis);
```

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>globalThis</title>
</head>
<body>
    <script>
        console.log(globalThis);
    </script>
</body>
</html>
```
