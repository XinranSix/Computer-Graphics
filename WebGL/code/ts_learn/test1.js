var isDone = false;
console.log(isDone);
var decLiteral = 6;
var hexLiteral = 0xf0d;
var binaryLiteral = 10;
var octalLiteral = 484;
console.log(decLiteral, hexLiteral, binaryLiteral, octalLiteral);
var name1 = 'bob';
var age = 37;
var sentence = "Hello, my name is ".concat(name1, ".\n\nI'll be ").concat(age + 1, " years old next month.");
console.log(sentence);
var list1 = [1, 2, 3];
var list2 = [1, 2, 3];
console.log(list1);
console.log(list2);
var x;
x = ['hello', 10];
console.log(x);
console.log(x[0].substring(1));
var Color;
(function (Color) {
    Color[Color["Red"] = 0] = "Red";
    Color[Color["Green"] = 1] = "Green";
    Color[Color["Blue"] = 2] = "Blue";
})(Color || (Color = {}));
var c = Color.Green;
console.log(c);
var notSure = 4;
notSure = 'maybe a string instead';
notSure = false;
