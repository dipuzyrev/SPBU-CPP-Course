package puzyrev.sem2.hw5.task1;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import java.net.URL;
import java.util.ResourceBundle;

/**
 * Controller for simple calculator.
 */
public class Controller implements Initializable {
    private Calculator calculator;
    @FXML
    private MenuButton operation;
    @FXML
    private Spinner firstValue;
    @FXML
    private Spinner secondValue;
    @FXML
    private TextField result;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        calculator = new Calculator();
        int minValue = calculator.getMinValue();
        int maxValue = calculator.getMaxValue();

        firstValue.setValueFactory(new SpinnerValueFactory.IntegerSpinnerValueFactory(minValue, maxValue));
        secondValue.setValueFactory(new SpinnerValueFactory.IntegerSpinnerValueFactory(minValue, maxValue));
    }

    /**
     * Recalculate result after operation was changed.
     * @param actionEvent
     */
    public void changeOperation(ActionEvent actionEvent) {
        MenuItem temp = (MenuItem) actionEvent.getSource();
        operation.setText(temp.getText());
        setResult();
    }

    /**
     * Recalcolate result after Spinner was changed.
     * @param mouseEvent
     */
    public void clickSpinner(MouseEvent mouseEvent) {
        setResult();
    }

    /**
     * Set calculated result to input.
     */
    private void setResult() {
        if (operation.getText().equals("")) {
            return;
        }

        int firstNumber = (Integer) firstValue.getValue();
        int secondNumber = (Integer) secondValue.getValue();

        if ((operation.getText().equals("/")) && (secondNumber == 0)) {
            result.setText("");
            return;
        }

        int answer = calculator.count(operation.getText(), firstNumber, secondNumber);
        result.setText(Integer.toString(answer));
    }
}