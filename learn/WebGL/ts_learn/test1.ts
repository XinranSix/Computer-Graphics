let isDone: boolean = false;

console.log(isDone);

let decLiteral: number = 6;
let hexLiteral: number = 0xf0d;
let binaryLiteral: number = 0b1010;
let octalLiteral: number = 0o744;

console.log(decLiteral, hexLiteral, binaryLiteral, octalLiteral);

let name1: string = 'bob';
let age: number = 37;
let sentence: string = `Hello, my name is ${name1}.

I'll be ${age + 1} years old next month.`;

console.log(sentence);

let list1: number[] = [1, 2, 3];

let list2: Array<number> = [1, 2, 3]

console.log(list1);
console.log(list2);

let x: [string, number];

x = ['hello', 10];
console.log(x);

console.log(x[0].substring(1));

enum Color {Red, Green, Blue}

let c: Color = Color.Green;

console.log(c);

let notSure: any = 4;
notSure = 'maybe a string instead';
notSure = false;


