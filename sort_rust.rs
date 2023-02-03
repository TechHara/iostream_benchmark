use std::io::{BufReader, BufRead, BufWriter, Write}; 
use std::fs::File;

fn main() -> std::io::Result<()> {
    let args: Vec<_> = std::env::args().collect();
    let input_file = if args.len() >= 2 { args[1].clone() } else { "/dev/stdin".to_owned() };
    let output_file = if args.len() >= 3 { args[2].clone() } else { "/dev/stdout".to_owned() };

    let ifs = BufReader::new(File::open(input_file)?);
    let mut ofs = BufWriter::new(File::create(output_file)?);

    let mut lines = Vec::new();
    for line in ifs.lines() {
        let line = line?;
        lines.push(line);
    }

    lines.sort_unstable();
    for line in lines.into_iter() {
        writeln!(ofs, "{}", line)?;
    }

    Ok(())
}