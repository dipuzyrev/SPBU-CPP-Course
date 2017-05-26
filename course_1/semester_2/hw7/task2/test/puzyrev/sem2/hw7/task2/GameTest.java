package puzyrev.sem2.hw7.task2;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class GameTest {
    @Test
    void testRow() {
        Game game = new Game();
        ArrayList<Integer> row = new ArrayList<>(Arrays.asList(1,4,2,5,3));
        addLabels(row, game);
        Label[] result = game.checkResults();

        assertTrue(result != null);
    }

    @Test
    void testCol() {
        Game game = new Game();
        ArrayList<Integer> row = new ArrayList<>(Arrays.asList(1,2,5,8));
        addLabels(row, game);
        Label[] result = game.checkResults();

        assertTrue(result != null);
    }

    @Test
    void testDiagonal() {

    }

    @Test
    void testNotEnded() {

    }

    private void addLabels(ArrayList<Integer> ids, Game game) {
        for (Integer id: ids) {
            Label label = new Label("");
            label.setId("f" + id);
            game.putValue(label);
        }
    }
}