use self::libraries::environment::Command;
use std::{env, fs};
mod libraries;
type Job = Box<dyn FnOnce() + 'static + Send>;
pub struct Application {
    command: Command,
}
impl Default for Application {
    fn default() -> Self {
        let command = env::args().collect::<Vec<String>>().into();
        Self { command }
    }
}
impl Application {
    pub fn run(self) {
        let help_ = || println!("todo");
        let converter_ = |c_name: &str, c_content: String| {
            let asm_name = format!("{}.asm", c_name);
            fs::write(asm_name, c_content).unwrap()
        };
        let unknown_ = || println!("todo");
        match self.command {
            Command::Help => help_(),
            Command::Run(c_name) => {
                let c_content = fs::read_to_string(c_name.as_str()).unwrap();
                converter_(c_name.as_str(), c_content)
            }
            Command::Unknown => unknown_(),
        }
    }
}
