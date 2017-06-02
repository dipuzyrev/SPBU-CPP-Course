package puzyrev.sem2.hw7.task2;

import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Paint;
import java.net.URL;
import java.util.ResourceBundle;

/**
 * Controller for Tic-tac-toe game.
 */
public class Controller implements Initializable {
    private Game game;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        game = new Game();
    }

    /**
     * Handle label clicking.
     * @param event mouse event
     */
    public void putValue(MouseEvent event) {
        Label field = (Label) event.getSource();

        String value = game.putValue(field);
        if (value != null) {
            field.setText(value);

            Label[] finalFields = game.checkResults();
            if (finalFields != null) {
                colorize(finalFields);
            }
        }
    }

    private void colorize(Label[] labels) {
        for (Label label: labels) {
            label.setTextFill(Paint.valueOf("red"));
        }
    }
}