fn main() {
    let mut s = String::from("Hello");

    s.push_str(", World!");

    println!("{}", s);

    let s1 = String::from("hello");
    let s2 = s1.clone();

    println!("{}", s1);
    println!("{}", s2);

    println!();

    let s = String::from("Hello World");

    take_ownership(s);

    let x = 5;
    makes_copy(x);
    println!("x: {}", x);

    println!();

    let s1 = gives_ownership();

    let s2 = String::from("Hello");

    let s3 = takes_and_gives_back(s2);

    println!("The value of s1 is {}", s1);
    println!("The value of s3 is {}", s3);

    println!();
}

fn take_ownership(some_string: String) {
    println!("{}", some_string);
}

fn makes_copy(some_number: i32) {
    println!("{}", some_number);
}

fn gives_ownership() -> String {
    let some_string = String::from("hello");
    some_string
}

fn takes_and_gives_back(s_string: String) -> String {
    s_string
}
