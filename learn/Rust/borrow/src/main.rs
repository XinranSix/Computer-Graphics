fn main() {
    let mut s1 = String::from("Hello");
    let len = calculate_length(&mut s1);

    println!("The legth of '{}' is {}.", s1, len);
}

fn calculate_length(s: &mut String) -> usize {
    s.push_str(", world");
    s.len()
}
