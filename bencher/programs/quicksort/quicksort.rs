use std::io;

fn swap(v: &mut Vec::<i32>, index1: usize, index2: usize) {
    let temp = v[index1];
    v[index1] = v[index2];
    v[index2] = temp;
}

fn partition(v: &mut Vec::<i32>, begin: usize, end: usize) -> i32 {
    let mut smaller_end = begin;
    for larger_end in begin..end {
        if v[larger_end] <= v[end] {
            swap(v, smaller_end, larger_end);
            smaller_end += 1;
        }
    }
    swap(v, smaller_end, end);
    return smaller_end as i32;
}

fn quicksort(v: &mut Vec::<i32>, begin: usize, end: usize) {
    if begin < end {
        let split = partition(v, begin, end);
        if split > 0 {
            quicksort(v, begin, (split-1) as usize);
        }
        quicksort(v, (split+1) as usize, end);
    }
}

fn main() {
    let mut num_buf = String::new();
    io::stdin().read_line(&mut num_buf).ok();
    let num: usize = match num_buf.trim().parse::<usize>() {
        Ok(a) => a,
        Err(_) => 0
    };

    let mut vec_buf = String::new();
    io::stdin().read_line(&mut vec_buf).ok();
    let mut int_vec: Vec<i32> = vec_buf.split_whitespace()
        .map(|s| s.parse().expect("parse error")).collect();

    quicksort(&mut int_vec, 0, num-1);
}