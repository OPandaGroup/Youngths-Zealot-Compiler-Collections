pub enum Command {
    Help,
    Run(String),
    Unknown,
}
impl From<Vec<String>> for Command {
    fn from(command: Vec<String>) -> Self {
        let mut command = command.into_iter();
        match command.len() {
            2 | 3 | 4 => match command.nth(1) {
                Some(c_name) => Self::Run(c_name),
                None => Self::Unknown,
            },
            _ => Self::Unknown,
        }
    }
}
