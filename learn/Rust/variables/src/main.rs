// const MAX_POINTS: u32 = 100_000;

fn main() {
    println!("Hello, world!");

    println!();

    let mut x = 5;
    println!("The value of x is {}", x);

    x = 6;
    println!("The value of x is {}", x);

    println!();

    let y = 5;
    println!("The value of y is {}", y);
    let y = y + 1;
    println!("The value of y is {}", y);
    let y = y * 2;
    println!("The value of y is {}", y);

    println!();

    let spaces = "    ";
    println!("The value of spaces is {}", spaces);
    let spaces = spaces.len();
    println!("The value of spaces is {}", spaces);

    println!();

    let guess: u32 = "42".parse().expect("Not a number");
    println!("The value of guess is {}", guess);

    /*
       标量类型：整数类型、浮点类型、布尔类型、字符类型
       整数类型：
           +--------+----------------+
           |length  |signed|unsigned |
           |--------|------|---------|
           |8-bit   |i8    |u8       |
           |16-bit  |i16   |u16      |
           |32-bit  |i32   |u32      |
           |64-bit  |i64   |u64      |
           |128-bit |i128  |u128     |
           |arch    |isize |usize    |
           +--------+------+---------+
       浮点类型：
           f32、f64
       布尔类型：
           bool (true、false)
       字符类型：
           char, 4-bit
    */
    let x = 2.0;
    let y: f32 = 4.0;
    println!("x is {}, y is {}", x, y);

    println!();

    /*
        复合类型：Tuple 和数组
    */
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("{}, {}, {}", x, y, z);
    println!("{}, {}, {}", tup.0, tup.1, tup.2);

    println!();

    let a = [1, 2, 3, 4, 5];
    println!("{}", a[0]);

    println!();
    another_function(5, 6);

    println!();
    println!("{}", plus_five(6));
}

fn another_function(x: i32, y: i32) {
    println!("The value of x is {}", x);
    println!("The value of y is {}", y);
}

fn plus_five(x: i32) -> i32 {
    x + 5
}
