struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 0,
    }
}

struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

fn main() {
    println!("Hello World");

    let mut user1 = User {
        email: String::from("acb@126.com"),
        username: String::from("Nikky"),
        active: true,
        sign_in_count: 556,
    };

    user1.email = String::from("anthoremail@126.com");

    let user2 = User {
        email: String::from("anthor@example.com"),
        username: String::from("anotherusename567"),
        ..user1
    };
}
