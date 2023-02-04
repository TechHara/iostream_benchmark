use std::io::{BufReader, BufRead, BufWriter, Write}; 
use std::fs::File;

/**
 * Copies input to output line by line
 * Usage: io [INPUT [OUTPUT]]
 * If INPUT/OUTPUT is omitted, stdin/stdout is assumed
 */
fn main() -> std::io::Result<()> {
    let args: Vec<_> = std::env::args().collect();
    let input_file = if args.len() >= 2 { args[1].clone() } else { "/dev/stdin".to_owned() };
    let output_file = if args.len() >= 3 { args[2].clone() } else { "/dev/stdout".to_owned() };

    let ifs = BufReader::new(File::open(input_file)?);
    let mut ofs = BufWriter::new(File::create(output_file)?);

    for line in ifs.lines() {
        let line = line?;
        writeln!(ofs, "{}", line)?;
    }

    Ok(())
}