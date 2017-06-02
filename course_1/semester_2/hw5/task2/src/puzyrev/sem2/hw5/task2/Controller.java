package puzyrev.sem2.hw5.task2;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;

/**
 * Controller for calculator.
 */
public class Controller {
    private StackCalculator calculator;
    @FXML
    private Label mainInput;
    @FXML
    private Label secondInput;

    public Controller() {
        calculator = new StackCalculator();
    }

    /**
     * Calculate result when pressed any button.
     * @param actionEvent action event
     */
    public void clickButton(ActionEvent actionEvent) {
        Button button = (Button) actionEvent.getSource();

        String command = button.getText();
        if (command.equals("C") || command.equals("=")) {
            secondInput.setText("");
        }

        if (command.equals("00")) {
            calculator.computing("0");
            calculator.computing("0");
        } else {
            calculator.computing(button.getText());
        }

        String output = calculator.getOutput();

        if (output.endsWith(" ")) {
            secondInput.setText(output);
            mainInput.setText("");
        } else {
            if (output.split(" ").length == 3) {
                mainInput.setText(output.split(" ")[2]);
            } else {
                mainInput.setText(output);
            }
        }
    }
}