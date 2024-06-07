enum FirstCommand {
    Help,
    Run,
    Version,
}
impl From<&str> for FirstCommand {
    fn from(command: &str) -> Self {
        match command {
            "-H" | "--help" => Self::Help,
            "-V" | "--version" => Self::Version,
            _ => Self::Run,
        }
    }
}
