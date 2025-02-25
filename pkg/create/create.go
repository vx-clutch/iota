package create

import "iota/pkg/errx"

func Create(name string, lang string) error {
  // code to copy template 
  // 'iota/project.layouts/' + name => '.'
  switch lang {
  default:
    errx.Errx(3, false, "incomplete feature")
    break
  }
  return nil
}
